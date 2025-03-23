# Linux Autodeafen X11 Part

Just clicks the `keycode provided from the last argument` button when started from Wine. Will be fixed in the future.


**Example:**

```bash
wine lnax.exe.so 78 # Clicks 'scroll lock'
```


**Example 2 (In Geode):**

```cpp
void spawn_deafen_process(int xkeycode) { // NEEDS TO BE COMPLIANT WITH XCB
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;

	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	std::string path = CCFileUtils::get()->fullPathForFilename("lnax.exe.so"_spr, true);

	auto keycodeArg = std::to_string(xkeycode).c_str();

	if (!CreateProcess(path.c_str(), (char*)keycodeArg, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi)) {
		log::error("Failed to launch Deafen program: {}", GetLastError());
		return;
	}
}
```


## Build

**Prerequesites:**

- `cmake`
- `gcc`
- `make`
- `libx11-dev`
- `libxext-dev`
- `libxtst-dev`
- `wine`


Set configure flags to:

`-DCMAKE_CXX_COMPILER=wineg++`
`-DCMAKE_C_COMPILER=winegcc`


Build in Release mode.