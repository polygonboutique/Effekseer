#include "ProcedualModelGenerator.h"
#include "../Effekseer.Model.h"
#include "../SIMD/Effekseer.SIMDUtils.h"
#include "ProcedualModelParameter.h"

#define _USE_MATH_DEFINES
#include <math.h>

namespace Effekseer
{

/*
	memo

	// Sugoi tube

	// wire

	// Rectangle

	// Box

	// Others

	// Filter
	// Twist
	// Jitter
	// Require normal
	// Calculate tangent
*/

struct RotatorSphere
{
	float Radius;

	Vec2f GetPosition(float value) const
	{
		float axisPos = -Radius + Radius * 2.0f * value;
		return sqrt(Radius * Radius - axisPos * axisPos);
	}
};

struct RotatorCone
{
	float Radius;
	float Length;

	Vec2f GetPosition(float value) const
	{
		float axisPos = Length * value;
		return Radius / Length * axisPos;
	}
};

struct RotatorCylinder
{
	float RadiusStart;
	float RadiusEnd;
	float Length;

	Vec2f GetPosition(float value) const
	{
		float axisPos = Length * value;
		return (RadiusEnd - RadiusStart) / Length * axisPos + RadiusStart;
	}
};

struct ProcedualMeshVertex
{
	Vec3f Position;
	Vec3f Normal;
	Vec3f Tangent;
	Vec2f UV;
};

struct ProcedualMeshFace
{
	std::array<int32_t, 3> Indexes;
};

struct ProcedualMesh
{
	CustomAlignedVector<ProcedualMeshVertex> Vertexes;
	CustomVector<ProcedualMeshFace> Faces;
};

template <typename T>
struct RotatorMeshGenerator
{
	float AxisValueMin;
	float AxisValueMax;
	float AngleMin;
	float AngleMax;
	T Rotator;

	Vec3f GetPosition(float axisValue, float angleValue) const
	{
		auto value = (AxisValueMax - AxisValueMin) * axisValue + AxisValueMin;
		auto angle = (AngleMax - AngleMin) * angleValue + AngleMin;

		Vec2f pos2d = Rotator.GetPosition(value);

		float s;
		float c;
		SinCos(angle, s, c);

		auto rx = pos2d.GetX() * s;
		auto rz = pos2d.GetX() * c;
		auto y = pos2d.GetY();

		return Vec3f(rx, y, rz);
	}

	ProcedualMesh Generate(int32_t axisDivision, int32_t angleDivision) const
	{
		assert(axisDivision > 1);
		assert(angleDivision > 1);

		ProcedualMesh ret;

		ret.Vertexes.resize(axisDivision * angleDivision);
		ret.Faces.resize((axisDivision - 1) * (angleDivision - 1) * 2);

		for (int32_t v = 0; v < axisDivision; v++)
		{
			for (int32_t u = 0; u < angleDivision; u++)
			{
				ret.Vertexes[u + v * angleDivision].Position = GetPosition(u / float(angleDivision - 1), v / float(axisDivision - 1));
				ret.Vertexes[u + v * angleDivision].UV = Vec2f(u / float(angleDivision - 1), v / float(axisDivision - 1));
			}
		}

		for (int32_t v = 0; v < axisDivision - 1; v++)
		{
			for (int32_t u = 0; u < angleDivision - 1; u++)
			{
				ProcedualMeshFace face0;
				ProcedualMeshFace face1;

				int32_t v00 = (u + 0) + (v + 0) * (axisDivision - 1);
				int32_t v10 = (u + 1) + (v + 0) * (axisDivision - 1);
				int32_t v01 = (u + 0) + (v + 1) * (axisDivision - 1);
				int32_t v11 = (u + 1) + (v + 1) * (axisDivision - 1);

				face0.Indexes[0] = v00;
				face0.Indexes[1] = v10;
				face0.Indexes[2] = v11;

				face1.Indexes[0] = v00;
				face1.Indexes[1] = v11;
				face1.Indexes[2] = v01;

				ret.Faces[(u + v * (angleDivision - 1)) * 2 + 0] = face0;
				ret.Faces[(u + v * (angleDivision - 1)) * 2 + 1] = face1;
			}
		}

		return ret;
	}
};

template <typename T>
struct RotatedWireMeshGenerator
{

	ProcedualMesh Generate(float angleBegin, float angleEnd, float axisBegin, float axisEnd, int32_t axisDivision, int32_t angleDivision)
	{
	}
};

static void CalculateNormal(const ProcedualMesh& mesh)
{
	CustomAlignedVector<Vec3f> faceNormals;
	CustomAlignedVector<Vec3f> faceTangents;

	faceNormals.resize(mesh.Faces.size());
	faceTangents.resize(mesh.Faces.size());

	for (size_t i = 0; mesh.Faces.size(); i++)
	{
		// TODO
	}
}

static Model* ConvertMeshToModel(const ProcedualMesh& mesh)
{
	CustomVector<Model::Vertex> vs;
	CustomVector<Model::Face> faces;

	vs.resize(mesh.Vertexes.size());
	faces.resize(mesh.Faces.size());

	for (size_t i = 0; i < vs.size(); i++)
	{
		vs[i].Position = ToStruct(mesh.Vertexes[i].Position);
		vs[i].Normal = ToStruct(mesh.Vertexes[i].Normal);
		vs[i].Tangent = ToStruct(mesh.Vertexes[i].Tangent);
		vs[i].UV = ToStruct(mesh.Vertexes[i].UV);
		Vector3D::Cross(vs[i].Binormal, vs[i].Normal, vs[i].Tangent);
		Vector3D::Normal(vs[i].Binormal, vs[i].Binormal);
		vs[i].VColor = Color(255, 255, 255, 255);
	}

	for (size_t i = 0; i < faces.size(); i++)
	{
		faces[i].Indexes[0] = mesh.Faces[i].Indexes[0];
		faces[i].Indexes[1] = mesh.Faces[i].Indexes[1];
		faces[i].Indexes[2] = mesh.Faces[i].Indexes[2];
	}

	return new Model(vs, faces);
}

Model* ProcedualModelGenerator::Generate(const ProcedualModelParameter* parameter)
{
	if (parameter == nullptr)
	{
		return nullptr;
	}

	if (parameter->Type == ProcedualModelType::Sphere)
	{
		auto generator = RotatorMeshGenerator<RotatorSphere>();
		generator.Rotator.Radius = parameter->Sphere.Radius;
		const auto generated = generator.Generate(parameter->AxisDivision, parameter->AngleDivision);
		ConvertMeshToModel(generated);
	}

	return nullptr;
}

void ProcedualModelGenerator::Ungenerate(Model* model)
{
	if (model != nullptr)
	{
		delete model;
	}
}

} // namespace Effekseer