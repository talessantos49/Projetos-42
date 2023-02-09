#!/usr/bin/sh
pip --version
# python -m path.py install

#pip install virtualenv
#python3 -m virtualenv my_env (é a criação do seu ambiente virtual com o nome "my_env em python3")
#source my_env/bin/activate (Para entrar no meu ambiente virtual!)
#deactivate (serve para sair do ambiente virtual)
python3 -m virtualenv my_env

source my_env/bin/activate

pip install -t local_lib --log logfile.log git+https://github.com/jaraco/path.git --force-reinstall --upgrade

python3 my_program.py