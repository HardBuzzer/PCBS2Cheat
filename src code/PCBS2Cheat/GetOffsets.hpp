#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>
#include "IL2CppResolver/Main.hpp"
#include "IL2CppResolver/Includes.hpp"

namespace GlobalPCBS2Offsets {
	uintptr_t s_instance = 0;
	uintptr_t m_state = 0;
	uintptr_t m_cash = 0;
	uintptr_t m_nextJobId = 0; //JobID :D

	uintptr_t SInstance() {
		s_instance = IL2CPP::Class::Utils::GetFieldOffset("CarrerStatus", "s_instance"); //S_Instance Offsets :D
		return s_instance;
	}
	uintptr_t MStateOffsets() {
		m_state = IL2CPP::Class::Utils::GetFieldOffset("CarrerStatus", "m_state"); //M_State Offsets :D
		return m_state;
	}
	uintptr_t M_Cash_Offsets()
	{
		m_cash = IL2CPP::Class::Utils::GetFieldOffset("CarrerStatus::State", "m_cash");
		return m_cash;
	}
	uintptr_t M_NextJobIDOffsets() {
		m_nextJobId = IL2CPP::Class::Utils::GetFieldOffset("CarrerStatus::State", "m_nextJobId");
		return m_nextJobId;
	}

	void GetOffsets() 
	{
		system("cls");
		std::cout << "S_Instance Offset: " << SInstance() << std::endl;
		std::cout << "MState Offset: " << MStateOffsets() << std::endl;
		std::cout << "MCash Offset: " << M_Cash_Offsets() << std::endl;
		std::cout << "MNextJobId Offset: " << M_NextJobIDOffsets() << std::endl;
	}
}
