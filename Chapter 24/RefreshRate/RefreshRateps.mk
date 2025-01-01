
RefreshRateps.dll: dlldata.obj RefreshRate_p.obj RefreshRate_i.obj
	link /dll /out:RefreshRateps.dll /def:RefreshRateps.def /entry:DllMain dlldata.obj RefreshRate_p.obj RefreshRate_i.obj kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib 

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL $<

clean:
	@del RefreshRateps.dll
	@del RefreshRateps.lib
	@del RefreshRateps.exp
	@del dlldata.obj
	@del RefreshRate_p.obj
	@del RefreshRate_i.obj
