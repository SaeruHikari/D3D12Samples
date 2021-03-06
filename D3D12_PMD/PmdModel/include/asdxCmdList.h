﻿//-------------------------------------------------------------------------------------------------
// File : asdxCmdList.h
// Desc : Command List Module.
// Copyright(c) Project Asura. All right reserved.
//-------------------------------------------------------------------------------------------------
#pragma once

//-------------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------------
#include <d3d12.h>
#include <asdxRef.h>


namespace asdx {

///////////////////////////////////////////////////////////////////////////////////////////////////
// GraphicsCmdList class
///////////////////////////////////////////////////////////////////////////////////////////////////
class GraphicsCmdList final
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

    //---------------------------------------------------------------------------------------------
    //! @brief      コンストラクタです.
    //---------------------------------------------------------------------------------------------
    GraphicsCmdList();

    //---------------------------------------------------------------------------------------------
    //! @brief      デストラクタです.
    //---------------------------------------------------------------------------------------------
    ~GraphicsCmdList();

    //---------------------------------------------------------------------------------------------
    //! @brief      初期化処理を行います.
    //!
    //! @param[in]      pDevice         デバイスです.
    //! @param[in]      type            コマンドリストタイプです.
    //! @retval true    初期化に成功.
    //! @retval false   初期化に失敗.
    //---------------------------------------------------------------------------------------------
    bool Init(
        ID3D12Device*           pDevice,
        D3D12_COMMAND_LIST_TYPE type,
        ID3D12PipelineState*    pPipelineState );

    //---------------------------------------------------------------------------------------------
    //! @brief      終了処理を行います.
    //---------------------------------------------------------------------------------------------
    void Term();

    //---------------------------------------------------------------------------------------------
    //! @brief      コマンドリストをリセットします.
    //---------------------------------------------------------------------------------------------
    void Clear( ID3D12PipelineState* pPipelineState );

    //---------------------------------------------------------------------------------------------
    //! @brief      遷移によるリソースバリアを設定します.
    //!
    //! @param[in]      pResource       リソース.
    //! @param[in]      before          変更前のリソース状態.
    //! @param[in]      after           変更後のリソース状態.
    //---------------------------------------------------------------------------------------------
    void Transition(
        ID3D12Resource* pResource,
        D3D12_RESOURCE_STATES before,
        D3D12_RESOURCE_STATES after);

    //---------------------------------------------------------------------------------------------
    //! @brief      コマンドリストを実行します.
    //!
    //! @param[in]      pQueue      コマンドキューです.
    //---------------------------------------------------------------------------------------------
    void Execute( ID3D12CommandQueue* pQueue );

    //---------------------------------------------------------------------------------------------
    //! @brief      アロケータを取得します.
    //!
    //! @return     コマンドアロケータを返却します.
    //---------------------------------------------------------------------------------------------
    ID3D12CommandAllocator* GetAllocator() const;

    //---------------------------------------------------------------------------------------------
    //! @brief      コマンドリストを取得します.
    //!
    //! @return     コマンドリストを返却します.
    //---------------------------------------------------------------------------------------------
    ID3D12CommandList* GetCmdList() const;

    //---------------------------------------------------------------------------------------------
    //! @brief      グラフィックスコマンドリストを取得します.
    //!
    //! @return     グラフィックスコマンドリストを返却します.
    //---------------------------------------------------------------------------------------------
    ID3D12GraphicsCommandList* GetGfxCmdList() const;

    //---------------------------------------------------------------------------------------------
    //! @brief      アロー演算子です.
    //---------------------------------------------------------------------------------------------
    ID3D12GraphicsCommandList* operator -> () const;

private:
    //=============================================================================================
    // private variables.
    //=============================================================================================
    RefPtr<ID3D12CommandAllocator>      m_Allocator;    //!< アロケータです.
    RefPtr<ID3D12GraphicsCommandList>   m_CmdList;      //!< コマンドリストです.

    //=============================================================================================
    // private methods.
    //=============================================================================================
    /* NOTHING */
};


} // namespace asdx
