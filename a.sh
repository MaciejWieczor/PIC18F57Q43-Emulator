PRO_FILE="kod.pro"
MAKEFILE_NAME="Makefile"
UI_SOURCE="ui/main_window.ui"
UI_DESTINATION="headers/ui_main_window.h"
EXE_NAME="kod"

echo "CREATING UI HEADER"
uic-qt5 $UI_SOURCE -o $UI_DESTINATION

echo "CREATING MAKEFILE FROM PROJECT .PRO"
qmake -o $MAKEFILE_NAME $PRO_FILE

echo "BUILDING PROJECT EXECUTABLE"
if make 
then
  echo "RUNNING GUI"
  ./$EXE_NAME
else
  echo "COMPILATION ERROR"
  make clean
fi
