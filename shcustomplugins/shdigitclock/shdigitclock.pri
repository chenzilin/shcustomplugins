currentdirname = shdigitclock

file = $${currentdirname}/$${currentdirname}.h
INCHEADERS += $${file}
HEADERS += $${file}

file = $${currentdirname}/$${currentdirname}.cpp
SOURCES += $${file}

file = $${currentdirname}/$${currentdirname}plugin.h
HEADERS += $${file}

file = $${currentdirname}/$${currentdirname}plugin.cpp
SOURCES += $${file}
