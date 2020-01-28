/*
            This file is part of: 
                NoahFrame
            https://github.com/ketoo/NoahGameFrame

   Copyright 2009 - 2020 NoahFrame(NoahGameFrame)

   File creator: lvsheng.huang
   
   NoahFrame is open-source software and you can redistribute it and/or modify
   it under the terms of the License; besides, anyone who use this file/software must include this copyright announcement.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef NF_BLUE_PRINT_VIRTUAL_MACHINE_H
#define NF_BLUE_PRINT_VIRTUAL_MACHINE_H

#include "NFComm/NFPluginModule/NFILogModule.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFIElementModule.h"
#include "NFComm/NFPluginModule/NFIClassModule.h"
#include "NFComm/NFPluginModule/NFIEventModule.h"
#include "NFComm/NFPluginModule/NFIBluePrintModule.h"


class NFBPVirtualMachine
{
public:
    NFBPVirtualMachine(NFIPluginManager* p, NF_SHARE_PTR<NFLogicBlock> logicBlock)
    {
        m_pBluePrintModule = p->FindModule<NFIBluePrintModule>();
        m_pElementModule = p->FindModule<NFIElementModule>();
        m_pClassModule = p->FindModule<NFIClassModule>();
        m_pEventModule = p->FindModule<NFIEventModule>();
        m_pLogModule = p->FindModule<NFILogModule>();
        
        mLogicBlock = logicBlock;

        mLogicBlock->running = true;


        StartToProcessMonitor();
    }

    virtual ~NFBPVirtualMachine() 
    {
        mLogicBlock->running = false;
    };

private:
    void StartToProcessMonitor();
    int GameEventIDCallBack(const int eventID, const NFDataList& dataList);

private:
    //first of all, find all monitors
    void StartMonitor(NF_SHARE_PTR<NFIMonitor> monitor);

private:
    NFIBluePrintModule* m_pBluePrintModule;
    NFIElementModule* m_pElementModule;
    NFIClassModule* m_pClassModule;
    NFIEventModule* m_pEventModule;
    NFILogModule* m_pLogModule;


    NF_SHARE_PTR<NFLogicBlock> mLogicBlock;
};


#endif