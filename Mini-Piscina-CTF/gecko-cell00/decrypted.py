import subprocess

# Caminho para o arquivo .gpg que você deseja descriptografar
arquivo_gpg = 'secret.txt.gpg'

# Loop para testar todas as combinações possíveis de senhas de 4 dígitos
for senha in range(10000):
    senha_formatada = f'{senha:04}'  # Formata a senha com 4 dígitos, preenchendo com zeros à esquerda
    try:
        # Tenta descriptografar o arquivo com a senha
        subprocess.run(['gpg', '--batch', '--yes', '--passphrase', senha_formatada, '--output', 'output.txt', arquivo_gpg], check=True)
        print(f'Senha correta encontrada: {senha_formatada}')
        break  # Sai do loop se a senha correta for encontrada
    except subprocess.CalledProcessError:
        pass  # Senha incorreta, continue testando

print('Teste concluído.')
