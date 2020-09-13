
#ifndef __EFFEKSEERRENDERER_DX9_GRAPHICS_DEVICE_H__
#define __EFFEKSEERRENDERER_DX9_GRAPHICS_DEVICE_H__

#include <Effekseer.h>
#include <assert.h>
#include <d3d9.h>
#include <set>

namespace EffekseerRendererDX9
{
namespace Backend
{

using Direct3DVertexBuffer9Ptr = std::unique_ptr<IDirect3DVertexBuffer9, Effekseer::ReferenceDeleter<IDirect3DVertexBuffer9>>;
using Direct3DIndexBuffer9Ptr = std::unique_ptr<IDirect3DIndexBuffer9, Effekseer::ReferenceDeleter<IDirect3DIndexBuffer9>>;
using Direct3DDevice9Ptr = std::unique_ptr<IDirect3DDevice9, Effekseer::ReferenceDeleter<IDirect3DDevice9>>;
using Direct3DVertexShader9Ptr = std::unique_ptr<IDirect3DVertexShader9, Effekseer::ReferenceDeleter<IDirect3DVertexShader9>>;
using Direct3DPixelShader9Ptr = std::unique_ptr<IDirect3DPixelShader9, Effekseer::ReferenceDeleter<IDirect3DPixelShader9>>;
using Direct3DVertexDeclaration9Ptr = std::unique_ptr<IDirect3DVertexDeclaration9, Effekseer::ReferenceDeleter<IDirect3DVertexDeclaration9>>;
using Direct3DTexture9Ptr = std::unique_ptr<IDirect3DTexture9, Effekseer::ReferenceDeleter<IDirect3DTexture9>>;

class GraphicsDevice;

class DirtiedBlock
{
	struct Block
	{
		int32_t offset;
		int32_t size;
	};

	std::vector<Block> blocks_;

public:
	/**
		@brief	Allocate block
		@return	whether is required to discard.
	*/
	bool Allocate(int32_t size, int32_t offset);
};

class DeviceObject
{
private:
public:
	virtual void OnLostDevice();

	virtual void OnResetDevice();
};

/**
	@brief	VertexBuffer of DirectX9
*/
class VertexBuffer
	: public DeviceObject,
	  public Effekseer::Backend::VertexBuffer
{
private:
	DirtiedBlock blocks_;

	GraphicsDevice* graphicsDevice_ = nullptr;
	Direct3DVertexBuffer9Ptr buffer_ = nullptr;
	int32_t size_ = 0;
	bool isDynamic_ = false;

public:
	VertexBuffer(GraphicsDevice* graphicsDevice);

	~VertexBuffer() override;

	bool Allocate(int32_t size, bool isDynamic);

	void Deallocate();

	void OnLostDevice() override;

	void OnResetDevice() override;

	bool Init(int32_t size, bool isDynamic);

	void UpdateData(const void* src, int32_t size, int32_t offset);

	IDirect3DVertexBuffer9* GetBuffer()
	{
		return buffer_.get();
	}
};

/**
	@brief	IndexBuffer of DirectX9
*/
class IndexBuffer
	: public DeviceObject,
	  public Effekseer::Backend::IndexBuffer
{
private:
	DirtiedBlock blocks_;

	GraphicsDevice* graphicsDevice_ = nullptr;
	Direct3DIndexBuffer9Ptr buffer_;
	int32_t elementCount_ = 0;
	int32_t stride_ = 0;

public:
	IndexBuffer(GraphicsDevice* graphicsDevice);

	~IndexBuffer() override;

	bool Allocate(int32_t elementCount, int32_t stride);

	void Deallocate();

	void OnLostDevice() override;

	void OnResetDevice() override;

	bool Init(int32_t elementCount, int32_t stride);

	void UpdateData(const void* src, int32_t size, int32_t offset);

	IDirect3DIndexBuffer9* GetBuffer()
	{
		return buffer_.get();
	};
};

/**
	@brief	GraphicsDevice of DirectX9
*/
class GraphicsDevice
	: public Effekseer::Backend::GraphicsDevice
{
private:
	Direct3DDevice9Ptr device_ = nullptr;
	std::set<DeviceObject*> objects_;

public:
	GraphicsDevice(IDirect3DDevice9* device);

	~GraphicsDevice() override;

	IDirect3DDevice9* GetDevice() const;

	void LostDevice();

	void ResetDevice();

	void Register(DeviceObject* deviceObject);

	void Unregister(DeviceObject* deviceObject);

	VertexBuffer* CreateVertexBuffer(int32_t size, const void* initialData, bool isDynamic) override;

	IndexBuffer* CreateIndexBuffer(int32_t elementCount, const void* initialData, Effekseer::Backend::IndexBufferStrideType stride) override;
};

} // namespace Backend

} // namespace EffekseerRendererDX9

#endif