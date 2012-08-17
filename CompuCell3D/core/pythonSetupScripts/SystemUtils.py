"This module contains platform specific initializations"

def setSwigPaths():
    import sys
    from os import environ
    import string
    import sys
    platform=sys.platform
    if platform.startswith('win'):
        
        swig_lib_install_path=environ["SWIG_LIB_INSTALL_DIR"]
        appended=sys.path.count(swig_lib_install_path)
        if not appended:
            sys.path.append(swig_lib_install_path)    
        # sys.path.append(environ["SWIG_LIB_INSTALL_DIR"])
        
        soslib_path=environ["SOSLIB_PATH"]
        appended=sys.path.count(soslib_path)
        if not appended:
            sys.path.append(soslib_path)    
        # sys.path.append(environ["SOSLIB_PATH"])
    else:
    
        swig_path_list=string.split(environ["SWIG_LIB_INSTALL_DIR"])
        for swig_path in swig_path_list:            
            appended=sys.path.count(swig_path)
            if not appended:
                sys.path.append(swig_path)    
        
            # sys.path.append(swig_path)

        soslib_path=environ["SOSLIB_PATH"]
        appended=sys.path.count(soslib_path)
        if not appended:
            sys.path.append(soslib_path)    
        # sys.path.append(environ["SOSLIB_PATH"])

def initializeSystemResources():
    platform=''
    RTLD_GLOBAL=0x0
    RTLD_NOW=0x0


    try:
        import sys
        platform=sys.platform
    except ImportError:
        print "Could not find sys module needed for setting upe system dependent resources. Check your Python installation. This is a basic module"
    else:
        platform=sys.platform
    
    print "Platform:",platform


    if platform.startswith('Linux') or platform.startswith('linux') or platform.startswith('linux2'):
        try:
            import dl
        except ImportError:
            print "Did not find dl module, will try manual dl initialization..."
            RTLD_GLOBAL=0x001000
            RTLD_NOW=0x00002
        else:
            RTLD_GLOBAL=dl.RTLD_GLOBAL
            RTLD_NOW=dl.RTLD_NOW
            
        sys.setdlopenflags(RTLD_GLOBAL | RTLD_NOW)
        
    elif platform.startswith('Darwin') or platform.startswith('darwin'):
        try:
            import dl
        except ImportError:
            print "Did not find dl module, will try manual dl initialization..."
            RTLD_GLOBAL=0x001000
            RTLD_NOW=0x00002
        else:
            RTLD_GLOBAL=dl.RTLD_GLOBAL
            RTLD_NOW=dl.RTLD_NOW
            
        sys.setdlopenflags(RTLD_GLOBAL | RTLD_NOW)
    elif platform.startswith('win'):
        print "MICROSOFT WINDOWS PLATFORM. Enjoy the bumpy ride ..."
    else:
        print "This platform is not supported for CompuCell Python Scripting"
        sys.exit()