﻿//-------------------------------------------------------------------------------------------------
// File : asdxBuffer.h
// Desc : Buffer.
// Copyright(c) Project Asura. All right reserved.
//-------------------------------------------------------------------------------------------------
#pragma once

//-------------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------------
#include <asdxDescriptorHeap.h>
#include <vector>


namespace asdx {

///////////////////////////////////////////////////////////////////////////////////////////////////
// ConstantBuffer class
///////////////////////////////////////////////////////////////////////////////////////////////////
class ConstantBuffer
{
    //=============================================================================================
    // list of friend classes and methods.
    //=============================================================================================
    /* NOTHING */

public:
    //=============================================================================================
    // public variables.
    //=============================================================================================
    /* NOTHING */

    //=============================================================================================
    // public methods.
    //=============================================================================================
    ConstantBuffer();
    ~ConstantBuffer();

    bool Init(ID3D12Device* pDevice, DescriptorHeap* pHeap, size_t size, uint32_t count);
    void Term();
    void Next();
    uint32_t GetCount() const;

    D3D12_GPU_VIRTUAL_ADDRESS   GetAddress  () const;
    D3D12_CPU_DESCRIPTOR_HANDLE GetHandleCPU() const;
    D3D12_GPU_DESCRIPTOR_HANDLE GetHandleGPU() const;
    void* GetPtr() const;

    D3D12_GPU_VIRTUAL_ADDRESS   GetAddress  (uint32_t index) const;
    D3D12_CPU_DESCRIPTOR_HANDLE GetHandleCPU(uint32_t index) const;
    D3D12_GPU_DESCRIPTOR_HANDLE GetHandleGPU(uint32_t index) const;
    void* GetPtr(uint32_t index) const;

    template<typename T>
    T* GetPtr() const
    { return reinterpret_cast<T>(GetPtr()); }

    template<typename T>
    T* GetPtr(uint32_t index) const
    { return reinterpret_cast<T>(GetPtr(index)); }

private:
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Instance strcture
    ///////////////////////////////////////////////////////////////////////////////////////////////
    struct Instance
    {
        RefPtr<ID3D12Resource>  pResource;
        RefPtr<Descriptor>      pDescriptor;
        void*                   pMappedPtr;
    };

    //=============================================================================================
    // private variables.
    //=============================================================================================
    std::vector<Instance>   m_Instance;
    uint32_t                m_Count;
    uint32_t                m_Index;

    //=============================================================================================
    // private methods.
    //=============================================================================================
    ConstantBuffer  (const ConstantBuffer&) = delete;
    void operator = (const ConstantBuffer&) = delete;
};


///////////////////////////////////////////////////////////////////////////////////////////////////
// VertexBuffer class
///////////////////////////////////////////////////////////////////////////////////////////////////
class VertexBuffer
{
    //=============================================================================================
    // list of friend classes and methods.
    //=============================================================================================
    /* NOTHING */

public:
    //=============================================================================================
    // public variables.
    //=============================================================================================
    /* NOTHING */

    //=============================================================================================
    // public methods.
    //=============================================================================================
    VertexBuffer();
    ~VertexBuffer();

    bool Init(ID3D12Device* pDevice, size_t size, size_t stride);
    void Term();
    void* Map() const;
    void  Unmap();
    D3D12_VERTEX_BUFFER_VIEW GetView() const;

private:
    //=============================================================================================
    // private variables.
    //=============================================================================================
    RefPtr<ID3D12Resource>      m_pResource;
    D3D12_VERTEX_BUFFER_VIEW    m_View;

    //=============================================================================================
    // private methods.
    //=============================================================================================
    void operator = (const VertexBuffer&) = delete;
    VertexBuffer    (const VertexBuffer&) = delete;
};


///////////////////////////////////////////////////////////////////////////////////////////////////
// IndexBufferView
///////////////////////////////////////////////////////////////////////////////////////////////////
class IndexBuffer
{
    //=============================================================================================
    // list of friend classes and methods.
    //=============================================================================================
    /* NOTHING */

public:
    //=============================================================================================
    // public variables.
    //=============================================================================================
    /* NOTHING */

    //=============================================================================================
    // public methods.
    //=============================================================================================
    IndexBuffer();
    ~IndexBuffer();

    bool Init(ID3D12Device* pDevice, size_t count);
    void Term();
    uint32_t* Map();
    void Unmap();

    D3D12_INDEX_BUFFER_VIEW GetView();
    size_t GetCount() const;

private:
    //=============================================================================================
    // private variables.
    //=============================================================================================
    RefPtr<ID3D12Resource>      m_pResource;
    D3D12_INDEX_BUFFER_VIEW     m_View;
    size_t                      m_Count;

    //=============================================================================================
    // private methods.
    //=============================================================================================
    void operator = (const IndexBuffer&) = delete;
    IndexBuffer     (const IndexBuffer&) = delete;
};

} // namespace asdx