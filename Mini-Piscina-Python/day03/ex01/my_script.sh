#!/usr/bin/bash
pip --version

python3 -m virtualenv my_env

source my_env/bin/activate

pip install -t local_lib --log logfile.log git+https://github.com/jaraco/path.git --force-reinstall --upgrade

python3 my_program.py