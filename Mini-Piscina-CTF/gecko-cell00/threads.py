import subprocess
from concurrent.futures import ThreadPoolExecutor

# Caminho para o arquivo .gpg que você deseja descriptografar
arquivo_gpg = 'secret.txt.gpg'

def testar_senha(senha):
    try:
        senha_formatada = f'{senha:04}'  # Formata a senha com 4 dígitos
        subprocess.run(['gpg', '--batch', '--yes', '--passphrase', senha_formatada, '--output', 'output.txt', arquivo_gpg], check=True)
        print(f'Senha correta encontrada: {senha_formatada}')
        return senha_formatada
    except subprocess.CalledProcessError:
        return print(senha)

# Número máximo de threads (ajuste conforme a capacidade do seu sistema)
max_threads = 4

# Crie um ThreadPoolExecutor com o número máximo de threads
with ThreadPoolExecutor(max_threads) as executor:
    futures = [executor.submit(testar_senha, senha) for senha in range(10000)]

    for future in futures:
        resultado = future.result()
        if resultado:
            print(f'Senha correta encontrada: {resultado}')
            exit(1)
            break

print('Teste concluído.')