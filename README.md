# pclub-hacking
`shahash.c` is the vulnerable file.

`assemble.c` is the assembly code used to obtain the shell code.

`assembly` is the compiled binary of `assemble.c`.

`hash.txt` will contain the calculated hash after running `shahash`
## Compiling instructions
```
gcc -fno-stack-protector shahash.c -o shahash
sudo chown root:samarth shahash
sudo chmod +s shahash
sudo execstack -s shahash
echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
```
## Usage
`shahash <filename>` will calculate hash of `<filename>` and put it into `hash.txt`
`shahash` will take input from stdin, put it into `random.txt`, calculate the hash of `random.txt` and put it in `hash.txt`

## Exploiting
`cat shellcode - | shahash` **should** work. If not, some adjustment of the return address might be required.
