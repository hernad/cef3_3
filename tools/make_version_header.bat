@echo off
..\third_party\python_26\python.exe tools\make_version_header.py --header include\cef_version.h --cef_version VERSION --chrome_version ../chrome/VERSION
