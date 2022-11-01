
<div align="center">
  <img src="https://user-images.githubusercontent.com/86013047/169532214-b6148f09-3e51-4c6d-90be-dd67ba469026.png"/>
</div>

# LIBFT

The first project in school 42, the purpose of this project is to create own C library. Based on libc functions and some additional functions;

Here, we can't use the real functions, we need to use our functions in all proccess;

And No Leaks will be tolerated. 

In this project, you must re-code a set of the libc functions, as defined in their man. Your functions will need to present the same prototype and behaviors as the originals. Your functions’ names must be prefixed by “ft_”. For instance strlen becomes ft_strlen.

### Libc functions
<table>
    <thead>
        <tr>
            <th colspan=3><h4>Biblioteca C <a href="https://www.tutorialspoint.com/c_standard_library/ctype_h.htm">&lt;ctype.h&gt;</h4></a></th>
        </tr>
        <tr>
            <th>Libft</th>
            <th>Português</th>
	    <th>English</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=ft_isalnum.c>ft_isalnum</a></td>
            <td>Checa se o caracter passado é alfanumérico.</td>
	    <td>Checks for an alphanumeric character.</td>
        </tr>
        <tr>
            <td><a href=ft_isalpha.c>ft_isalpha</a></td>
            <td>Checa se o caracter passado é alfabético.</td>
	    <td>Checks for an alphabetic character.</td>
        </tr>
        <tr>
            <td><a href=ft_isascii.c>ft_isascii</a></td>
            <td>Checa se o caracter passado é ASCII.</td>
	    <td>Checks whether c fits into the ASCII character set.</td>
        </tr>
        <tr>
            <td><a href=ft_isdigit.c>ft_isdigit</a></td>
            <td>Checa se o caracter passado é um decimal.</td>
	    <td>Checks for a digit (0 through 9).</td>
        </tr>
        <tr>
            <td><a href=ft_isprint.c>ft_isprint</a></td>
            <td>Checa se o caracter passado é  printável.</td>
	    <td>Checks for any printable character.</td>
        </tr>
        <tr>
            <td><a href=ft_tolower.c>ft_tolower</a></td>
            <td>Converte letra maiúsculas em minúsculas.</td>
	    <td>Convert char to lowercase.</td>
        </tr>
        <tr>
            <td><a href=ft_toupper.c>ft_toupper</a></td>
            <td>Converte letras minúsculas para maiúsculas.</td>
	    <td>Convert char to uppercase.</td>
        </tr>
    </tbody>
</table>

---

<table>
    <thead>
        <tr>
            <th colspan=3><h4>Biblioteca C <a href="https://www.tutorialspoint.com/c_standard_library/string_h.htm">&lt;string.h&gt;</h4></a></th>
        </tr>
        <tr>
            <th>Libft</th>
            <th>Português</th>
	    <th>English</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=ft_bzero.c>ft_bzero</a></td>
            <td>Apaga os dados em 'n' bytes no bloco de memória e seta zeros.</td>
	    <td>Erase data and set zero in 'n' bytes.</td>
        </tr>
        <tr>
            <td><a href=ft_memchr.c>ft_memchr</a></td>
            <td>Procura pela primeira ocorrência do caracter c nos primeiros 'n' bytes da string.</td>
	    <td>Scan memory for a character</td>
        </tr>
        <tr>
            <td><a href=ft_memcmp.c>ft_memcmp</a></td>
            <td>Compara os primeiros 'n' bytes da str1 e str2.</td>
	    <td>Compare the firsts 'n' bytes of str1 and str2.</td>
        </tr>
        <tr>
            <td><a href=ft_memcpy.c>ft_memcpy</a></td>
            <td>Copia 'n' caracteres do src para dest.</td>
	    <td>Copy 'n' characters of src to dest.</td>
        </tr>
        <tr>
            <td><a href=ft_memmove.c>ft_memmove</a></td>
            <td>Copia 'n' caracteres do src para o dst de forma não destrutiva.</td>
	    <td>Copy 'n' characters of src to dst without destruct string.</td>
        </tr>
        <tr>
            <td><a href=ft_memset.c>ft_memset</a></td>
            <td>Copia o caractere c para os primeiros 'n' caracteres da string.</td>
	    <td>Copy the character c to 'n' firts characters of string.</td>
        </tr>
        <tr>
            <td><a href=ft_strchr.c>ft_strchr</a></td>
            <td>Procura pela primeira ocorrência do caractere c na string.</td>
	    <td>Scan for the first occurrence of character c at string.</td>
        </tr>
        <tr>
            <td><a href=ft_strlcat.c>ft_strlcat</a></td>
            <td>Acrescenta a string src ao final de dst.</td>
	    <td>Concatenate a string(src) to another string (dst).</td>
        </tr>
        <tr>
            <td><a href=ft_strlcpy.c>ft_strlcpy</a></td>
            <td>Copia até o tamanho dest - 1 caracteres da string src a dst.</td>
	    <td>Copy string to an specific size.</td>
        </tr>
        <tr>
            <td><a href=ft_strlen.c>ft_strlen</a></td>
            <td>Computa o tamanho da string, mas não inclui caracteres NULL.</td>
	    <td>Calculate the length of a string without character NULL.</td>
        </tr>
        <tr>
            <td><a href=ft_strncmp.c>ft_strncmp</a></td>
            <td>Compara, no máximo, os primeiros 'n' bytes de str1 e str2.</td>
	    <td>Compare two strings until 'n' bytes character.</td>
        </tr>
        <tr>
            <td><a href=ft_strnstr.c>ft_strnstr</a></td>
            <td>Localiza a primeira ocorrência da string pequena na string grande.</td>
	    <td>Locate a substring in a string.</td>
        </tr>
        <tr>
            <td><a href=ft_strrchr.c>ft_strrchr</a></td>
            <td>Procura a última ocorrência do carácter c na string.</td>
	    <td>Locate a character in a string.</td>
        </tr>
    </tbody>
</table>

---

<table>
    <thead>
        <tr>
            <th colspan=3><h4>C Library <a href="https://www.tutorialspoint.com/c_standard_library/stdlib_h.htm">&lt;stdlib.h&gt;</h4></a></th>
        </tr>
        <tr>
            <th>Libft</th>
            <th>Português</th>
	    <th>English</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=ft_atoi.c>ft_atoi</a></td>
            <td>Converte string em inteiro.</td>
	    <td>Convert a string to an interger.</td>
        </tr>
        <tr>
            <td><a href=ft_calloc.c>ft_calloc</a></td>
            <td>Aloca o espaço requisitado e inicializa com 0 bytes.</td>
	    <td>Allocates memory and sets its bytes values to 0.</td>
        </tr>
    </tbody>
 </table>
 
 ---
 
 <table>
    <thead>
        <tr>
            <th colspan=3><h4>Biblioteca C não padrão</h4></a></th>
        </tr>
        <tr>
            <th>Libft</th>
            <th>Português</th>
	    <th>English</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=ft_itoa.c>ft_itoa</a></td>
            <td>Converte inteiro em string (char *).</td>
	    <td>Converts a number into a string.</td>
        </tr>
        <tr>
            <td><a href=ft_putchar_fd.c>ft_putchar_fd</a></td>
            <td>Retorna o caracter c no file descriptor.</td>
	    <td>Output a char to a file descriptor.</td>
        </tr>
        <tr>
            <td><a href=ft_putendl_fd.c>ft_putendl_fd</a></td>
            <td>Retorna a string seguido de uma nova linha.</td>
	    <td>Output a string to a file descriptor, followed by a new line.</td>
        </tr>
        <tr>
            <td><a href=ft_putnbr_fd.c>ft_putnbr_fd</a></td>
            <td>Retorna o inteiro.</td>
	    <td>Output a number to a file descriptor.</td>
        </tr>
        <tr>
            <td><a href=ft_putstr_fd.c>ft_putstr_fd</a></td>
            <td>Retorna uma string.</td>
	    <td>Output a string to a file descriptor.</td>
        </tr>
        <tr>
            <td><a href=ft_strdup.c>ft_strdup</a></td>
            <td>Retorna um ponteiro a uma string, que é um duplicado da string passada.</td>
	    <td>Creates a dupplicate for the string passed as parameter.</td>
        </tr>
        <tr>
            <td><a href=ft_striteri.c>ft_striteri</a></td>
            <td>Aplica uma função a cada caracter da string.</td>
	    <td>Applies a function to each character of a string.</td>
        </tr>
        <tr>
            <td><a href=ft_strjoin.c>ft_strjoin</a></td>
            <td>Devolve uma nova string, que é o resultado da concatenação de 's1' e 's2'.</td>
	    <td>Concatenates two strings.</td>
        </tr>
        <tr>
            <td><a href=ft_strmapi.c>ft_strmapi</a></td>
            <td>Aplica uma função a cada carácter da string de caracteres para criar uma nova string</td>
	    <td>Applies a function to each character of a string.</td>
        </tr>
        <tr>
            <td><a href=ft_strtrim.c>ft_strtrim</a></td>
            <td>Devolve uma cópia de 's1' com os caracteres especificados em 'set' removidos do início e do fim da string.</td>
	    <td>Trims the beginning and end of string with specific set of chars.</td>
        </tr>
        <tr>
            <td><a href=ft_substr.c>ft_substr</a></td>
            <td>Devolve uma substring da string 's'. A substring começa no índice 'start' e é de tamanho máximo 'len'.</td>
	    <td>Returns a substring from a string.</td>
        </tr>
    </tbody>
</table>
