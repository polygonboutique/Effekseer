#ifndef __EFFEKSEER_PROCEDUAL_MODEL_PARAMETER_H__
#define __EFFEKSEER_PROCEDUAL_MODEL_PARAMETER_H__

#include "../Utils/Effekseer.BinaryReader.h"
#include <stdint.h>
#include <stdio.h>

namespace Effekseer
{

enum class ProcedualModelType : int32_t
{
	Sphere,
	Cone,
	Cylinder,
};

struct ProcedualModelParameter
{
	ProcedualModelType Type;

	float AngleBegin;
	float AngleEnd;
	float AxisBegin;
	float AxisEnd;
	int AxisDivision;
	int AngleDivision;

	float TwistPower;
	float TwistUpPower;
	// hoge,,,

	union
	{
		struct
		{
			float Radius;
		} Sphere;

		struct
		{
			float Radius;
			float Length;
		} Cone;

		struct
		{
			float RadiusBegin;
			float RadiusEnd;
			float Length;
		} Cylinder;
	};

	bool operator<(const ProcedualModelParameter& rhs) const
	{
		if (Type != rhs.Type)
		{
			return static_cast<int32_t>(Type) < static_cast<int32_t>(Type);
		}

		if (Type == ProcedualModelType::Sphere)
		{
			if (Sphere.Radius != rhs.Sphere.Radius)
				return Sphere.Radius < rhs.Sphere.Radius;
		}

		return false;
	}

	template <bool T>
	bool Load(BinaryReader<T>& reader)
	{
		reader.Read(Type);
		reader.Read(AxisDivision);
		reader.Read(AngleDivision);
		reader.Read(AngleBegin);
		reader.Read(AngleEnd);
		reader.Read(AxisBegin);
		reader.Read(AxisEnd);

		if (Type == ProcedualModelType::Sphere)
		{
			reader.Read(Sphere.Radius);
		}

		return true;
	}
};

} // namespace Effekseer

#endif