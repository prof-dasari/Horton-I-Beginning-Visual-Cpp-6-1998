
ATLSignalps.dll: dlldata.obj ATLSignal_p.obj ATLSignal_i.obj
	link /dll /out:ATLSignalps.dll /def:ATLSignalps.def /entry:DllMain dlldata.obj ATLSignal_p.obj ATLSignal_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del ATLSignalps.dll
	@del ATLSignalps.lib
	@del ATLSignalps.exp
	@del dlldata.obj
	@del ATLSignal_p.obj
	@del ATLSignal_i.obj
