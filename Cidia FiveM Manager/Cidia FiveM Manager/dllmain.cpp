#include "pch.h"
#include "LuaScriptRuntime.h"
#include "v8.h"
#include "includes.h"
#include "font/font_awesome.h"
#include "font.h"

namespace globals
{
	bool window = true;
}
static char scriptCodeBuffer[10000000];

void Execute()
{
	std::string script = scriptCodeBuffer;
	fx::LuaScriptRuntime* Runtime = new fx::LuaScriptRuntime();
	Runtime->m_stream->Write(script);
	Runtime->m_stream->ScriptState(Runtime->LUA());
	Runtime->LoadSystemFile("@@hardcap/scriptIsolate.lua");
}

DWORD WINAPI manager(LPVOID lr)
{
	Execute();
	return 0;
}

/*void ResetEvent(HMODULE hObject)
{
	typedef char* (__fastcall* is_hooked)(HMODULE a);
	is_hooked execute_hook = (is_hooked)((uintptr_t)GetModuleHandle(L"adhesive.dll") + 0xAD8096);
	execute_hook(hObject);
}
void SetEvent(HMODULE hObject)
{
	typedef char* (__fastcall* is_hooked)(HMODULE a);
	is_hooked execute_hook = (is_hooked)((uintptr_t)GetModuleHandle(L"adhesive.dll") + 0xAD8085);
	execute_hook(hObject);
}

#define print(format, ...) fprintf (stderr, format, __VA_ARGS__)
DWORD WINAPI Main(LPVOID prm)
{
	cidia::v8::adhesive().Nop(0x39903C8, cidia::v8::adhesive().get_adhesive_address());
	cidia::v8::adhesive().Nop(0x39905F8, cidia::v8::adhesive().get_adhesive_address());
	HMODULE hObject = cidia::v8::adhesive().Get_Object(0x39896F0, L"adhesive.dll");
	SetEvent(hObject);
	ResetEvent(hObject);
	/*
	setevent 0xAD8085
	*/

	//resetevent

	   //cidia::v8::adhesive->messegse_box(L"test", L"fuck fivem");
	   // adhesive->exit_process(0x0);
		//adhesive->Nop(0x9157D0, adhesive->get_adhesive_address());
		//adhesive->Nop(0x39903C8, adhesive->get_adhesive_address());//118836B = IDidntDoNothing Imports from ros-patches-five.dll 
		//adhesive->Nop(0x118836B, adhesive->get_adhesive_address());//30F8726
	   // adhesive->Nop(0x30F8726, adhesive->get_adhesive_address());//33A8DB0 = ReportEventW
		//adhesive->Nop(0x39905F8, adhesive->get_adhesive_address());//0x39905F8 = class fwEvent<bool *> ConHost::OnShouldDrawGui Imports from conhost-v2.dll
	   // adhesive->Nop(0xC60319, adhesive->get_adhesive_address());//0xC60319 = void (__stdcall *GetSystemInfo)(LPSYSTEM_INFO lpSystemInfo)
		//adhesive->Nop(0x33A8DB0, adhesive->get_adhesive_address());// bypass shoutdown socket
	//FreeLibraryAndExitThread((HMODULE)prm, 0);

	//return 0;
//}*/

void SetupImGuiStyle()
{
	ImGuiStyle& style = ImGui::GetStyle();

	style.Alpha = 1.0f;
	style.WindowPadding = ImVec2(8.0f, 8.0f);
	style.WindowRounding = 0.0f;
	style.WindowBorderSize = 1.0f;
	style.WindowMinSize = ImVec2(32.0f, 32.0f);
	style.WindowTitleAlign = ImVec2(0.0f, 0.5f);
	style.WindowMenuButtonPosition = ImGuiDir_Left;
	style.ChildRounding = 0.0f;
	style.ChildBorderSize = 1.0f;
	style.PopupRounding = 0.0f;
	style.PopupBorderSize = 1.0f;
	style.FramePadding = ImVec2(4.0f, 3.0f);
	style.FrameRounding = 0.0f;
	style.FrameBorderSize = 0.0f;
	style.ItemSpacing = ImVec2(8.0f, 4.0f);
	style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
	style.IndentSpacing = 21.0f;
	style.ColumnsMinSpacing = 6.0f;
	style.ScrollbarSize = 14.0f;
	style.ScrollbarRounding = 9.0f;
	style.GrabMinSize = 10.0f;
	style.GrabRounding = 0.0f;
	style.TabRounding = 2.0f;
	style.TabBorderSize = 0.0f;
	style.ColorButtonPosition = ImGuiDir_Right;
	style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
	style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

	style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.4980392158031464f, 0.4980392158031464f, 0.4980392158031464f, 1.0f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.05882352963089943f, 0.05882352963089943f, 0.05882352963089943f, 0.9399999976158142f);
	style.Colors[ImGuiCol_ChildBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.0784313753247261f, 0.0784313753247261f, 0.0784313753247261f, 0.9399999976158142f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.4274509847164154f, 0.4274509847164154f, 0.4980392158031464f, 0.5f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.2489270567893982f, 0.2489245682954788f, 0.2489245682954788f, 0.5400000214576721f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.3776823878288269f, 0.3776786029338837f, 0.3776786029338837f, 1.0f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.412013053894043f, 0.4120150506496429f, 0.4120171666145325f, 0.6700000166893005f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.03921568766236305f, 0.03921568766236305f, 0.03921568766236305f, 1.0f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.0f, 0.0f, 0.0f, 0.5099999904632568f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.1372549086809158f, 0.1372549086809158f, 0.1372549086809158f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.01960784383118153f, 0.01960784383118153f, 0.01960784383118153f, 0.5299999713897705f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3098039329051971f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.407843142747879f, 0.407843142747879f, 0.407843142747879f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.5098039507865906f, 0.5098039507865906f, 0.5098039507865906f, 1.0f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.9999899864196777f, 0.9999945759773254f, 1.0f, 1.0f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(1.0f, 0.9999899864196777f, 0.9999899864196777f, 1.0f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.2317573428153992f, 0.2317588180303574f, 0.2317596673965454f, 0.4000000059604645f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.5321835279464722f, 0.5321863889694214f, 0.5321888327598572f, 1.0f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.3390523791313171f, 0.3390548527240753f, 0.3390557765960693f, 0.3100000023841858f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(1.0f, 0.0f, 0.0f, 0.800000011920929f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.5965665578842163f, 0.5965605974197388f, 0.5965605974197388f, 1.0f);
	style.Colors[ImGuiCol_Separator] = ImVec4(0.4274509847164154f, 0.4274509847164154f, 0.4980392158031464f, 0.5f);
	style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.7490196228027344f, 0.09803923219442368f, 0.09803923219442368f, 0.7799999713897705f);
	style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.7490196228027344f, 0.2824370861053467f, 0.09803923219442368f, 1.0f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.9764705896377563f, 0.2588235437870026f, 0.2588235437870026f, 0.2000000029802322f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.9764705896377563f, 0.2588235437870026f, 0.2588235437870026f, 0.6700000166893005f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.0f, 0.0f, 0.0f, 0.949999988079071f);
	style.Colors[ImGuiCol_Tab] = ImVec4(0.1373390555381775f, 0.1332129836082458f, 0.1332129836082458f, 0.8619999885559082f);
	style.Colors[ImGuiCol_TabHovered] = ImVec4(1.0f, 0.0f, 0.0f, 0.800000011920929f);
	style.Colors[ImGuiCol_TabActive] = ImVec4(0.3948458135128021f, 0.3948476016521454f, 0.3948497772216797f, 1.0f);
	style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.06666667014360428f, 0.1019607856869698f, 0.1450980454683304f, 0.9724000096321106f);
	style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(1.0f, 0.0f, 0.0f, 0.3499999940395355f);
	style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.0f, 0.0f, 0.0f, 0.8999999761581421f);
	style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9764705896377563f, 1.0f);
	style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 1.0f, 1.0f, 0.699999988079071f);
	style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.2000000029802322f);
	style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.3499999940395355f);
}

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;

void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);

	ImFontConfig font;
	font.FontDataOwnedByAtlas = false;

	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	io.IniFilename = nullptr;
	io.LogFilename = nullptr;

	static const ImWchar icons_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
	ImFontConfig icons_config;

	icons_config.MergeMode = true;
	icons_config.PixelSnapH = true;



	ImFontConfig CustomFont;
	CustomFont.FontDataOwnedByAtlas = false;


	io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Bahnschrift.ttf", 16);
	io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 12.0f, &icons_config, icons_ranges);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

bool init = false;
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}

	static char searchString[20];
	static int selectedResourceIndex = 0;
	static int selectedDumpIndex = 0;

	if (GetAsyncKeyState(VK_INSERT) & 1)
		globals::window = !globals::window;
	ImGuiIO& io = ImGui::GetIO();
	io.MouseDrawCursor = globals::window;

	if (globals::window)
	{
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		SetupImGuiStyle();
		ImGui::SetNextWindowSize(ImVec2(720, 409));



		if (ImGui::Begin("ImGui Window", &globals::window, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse))
		{
			if (ImGui::BeginTabBar("TabBar"))
			{
				if (ImGui::BeginTabItem("Executor"))
				{
					ImGui::BeginChild("ExecutorChild", ImVec2(0, -22), true);


					ImVec2 inputSize(688, 307);

					ImGui::InputTextMultiline(" ", scriptCodeBuffer, sizeof(scriptCodeBuffer), inputSize, ImGuiInputTextFlags_None);
					ImGui::EndChild();

					if (ImGui::Button("Execute "))
					{
						CreateThread(0, 0, manager, 0, 0, 0);
					}

					ImGui::SameLine();

					if (ImGui::Button("Execute From file"))
					{

					}

					ImGui::SameLine();

					ImGui::EndTabItem();
				}
			}
			ImGui::End();
		}
		ImGui::Render();



		pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	}
	return oPresent(pSwapChain, SyncInterval, Flags);



}

DWORD WINAPI MainThread(LPVOID lpReserved)
{
	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)&oPresent, hkPresent);
			init_hook = true;
		}
	} while (!init_hook);
	return TRUE;
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hMod);
		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
}