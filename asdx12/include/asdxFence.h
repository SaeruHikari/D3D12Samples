﻿//-------------------------------------------------------------------------------------------------
// File : Fence.h
// Desc : Fence Module.
// Copyright(c) Pocol. All right reserved.
//-------------------------------------------------------------------------------------------------
#pragma once

//-------------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------------
#include <d3d12.h>
#include <asdxRefPtr.h>


namespace asdx {

///////////////////////////////////////////////////////////////////////////////////////////////////
// Fence class
///////////////////////////////////////////////////////////////////////////////////////////////////
class Fence
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
    Fence();

    //---------------------------------------------------------------------------------------------
    //! @brief      デストラクタです.
    //---------------------------------------------------------------------------------------------
    ~Fence();

    //---------------------------------------------------------------------------------------------
    //! @brief      初期化処理を行います.
    //!
    //! @param[in]      pDevice         デバイスです.
    //! @retval true    初期化に成功.
    //! @retval false   初期化に失敗.
    //---------------------------------------------------------------------------------------------
    bool Init(ID3D12Device* pDevice);

    //---------------------------------------------------------------------------------------------
    //! @brief      終了処理を行います.
    //---------------------------------------------------------------------------------------------
    void Term();

    //---------------------------------------------------------------------------------------------
    //! @brief      シグナル状態になるまで指定された時間待機します.
    //!
    //! @param[in]      pQueue          コマンドキューです.
    //! @param[in]      timeout         タイムアウト時間(ミリ秒).
    //---------------------------------------------------------------------------------------------
    void Wait(ID3D12CommandQueue* pQueue, UINT timeout);

    //---------------------------------------------------------------------------------------------
    //! @brief      シグナル状態になるまでずっと待機します.
    //!
    //! @param[in]      pQueue          コマンドキューです.
    //---------------------------------------------------------------------------------------------
    void Sync(ID3D12CommandQueue* pQueue);

private:
    //=============================================================================================
    // private variables.
    //=============================================================================================
    RefPtr<ID3D12Fence> m_pFence;           //!< フェンスです.
    HANDLE              m_Event;            //!< イベントです.
    UINT                m_Counter;          //!< 現在のカウンターです.

    //=============================================================================================
    // private methods.
    //=============================================================================================
    Fence           (const Fence&) = delete;    // アクセス禁止.
    void operator = (const Fence&) = delete;    // アクセス禁止.
};

} // namespace asdx