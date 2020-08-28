TITLE Program 6     (Addiego_Emily_program6.asm)

; Author: Emily Addiego
; Last Modified: 3/15/2020
; OSU email address: addiegoe@oregonstate.edu
; Course Number/section: 271/400
; Project number: 6            Due Date: 3/15/2020
; Description: This program uses macros and low-level
; I/O procedures to get 10 numbers from the user, validate
; user input, display the numbers entered, display the
; total sum, and display the rounded average.

INCLUDE Irvine32.inc

ARRAYSIZE = 10						;size of number array
MAXLENGTH = 11						;max length for 10-digit string

;********************************************************
; Macro to get string from user input
; receives: prompt for user, memory location for string
; returns: string stored in memory location
; preconditions: none
; registers changed: none
;********************************************************
getString MACRO inputName, prompt
push ecx
push edx

mov edx,prompt
call WriteString
mov edx,inputName					;buffer in edx					
mov ecx,32							;assume entered string will fit into 32 bits
call ReadString						;store string in place

pop edx								;restore all registers
pop ecx
ENDM


;*********************************************************
; Macro to display string
; receives: memory location of string
; returns: none
; preconditions: none
; registers changed: none
;*********************************************************
displayString MACRO strLocation
push edx							;preserve edx register

mov edx,strLocation					;write string from location
call WriteString

pop edx
ENDM

.data
iString		BYTE	MAXLENGTH DUP(?)	;user input string
oString		BYTE	MAXLENGTH DUP(?)	;number converted back to string
numbers		SDWORD	ARRAYSIZE DUP(?)	;array of numbers
lineNum     SDWORD  1                   ;line number for EC
pTitle		BYTE	"Macros and Low-level I/O Procedures, by Emily Addiego",0
line1		BYTE	"Please enter 10 numbers (signed numbers OK).",0
line2		BYTE	"Numbers must not contain letters or symbols (besides + and 1). Numbers must fit into a 32-bit register.",0
line3		BYTE	"At the end of the program, I'll print a list of your numbers, their sum, and their rounded average.",0
EC1			BYTE	"**EC: This program numbers lines of input and displays the number entered and a running total.",0
numP		BYTE	"Please enter a number: ",0
badInput	BYTE	"Sorry, that's not valid input. Please try again.",0
currTitle   BYTE    "You just entered: ",0
currSum     BYTE    "The running total of your numbers so far is: ",0
arrayTitle	BYTE	"You entered the following numbers: ",0
sumTitle	BYTE	"The sum of all your numbers is: ",0
commaSpace	BYTE	", ",0
periodSpace BYTE    ". ",0
avgTitle	BYTE	"The average (rounded down) is: ",0
farewell	BYTE	"The program is done! Goodbye!",0

.code

main PROC

;parameters and call for intro procedure
push OFFSET pTitle
push OFFSET line1
push OFFSET line2
push OFFSET line3
push OFFSET EC1
call intro
call Crlf

;parameters and call to fill array
push OFFSET currSum
push OFFSET currTitle
push lineNum
push OFFSET periodSpace
push OFFSET oString
push ARRAYSIZE
push OFFSET numbers
push OFFSET badInput
push OFFSET iString
push OFFSET numP
call fillArray
call Crlf

;parameters and call to printArray
push OFFSET arrayTitle
push OFFSET commaSpace
push OFFSET numbers
push OFFSET iString
push OFFSET oString
call printArray
call Crlf

;parameters and call to display sum and avg
push OFFSET numbers
push OFFSET sumTitle
push OFFSET avgTitle
push OFFSET iString
push OFFSET oString
call calculate
call Crlf
call Crlf

;parameters and call for goodbye procedure
push OFFSET farewell
call byeBye



exit						;exit to operating system
main ENDP


;procedures 
;********************************************************
;Procedure to introduce the program
;receives: title, instructions (passed by reference)
;returns:none
;registers modified:none
;preconditions: requires displayString macro
;********************************************************
intro PROC
push ebp
mov ebp,esp
displayString [ebp + 24]				;print each line of title and instructions
call Crlf                               ;by passing to displayString
call Crlf
displayString [ebp + 20]
call Crlf
displayString [ebp + 16]
call Crlf
displayString [ebp + 12]
call Crlf
displayString [ebp + 8]
call Crlf
pop ebp
ret 16
intro ENDP


;*******************************************************
;Procedure to read and validate the user's string of digits
;receives: input string, output string, array, input prompt, 
;bad input message, period and space (all by reference)
;line number (by value)
;returns: digit conversion of input string in array element
;preconditions: requires displayString and getString macros,
;calls writeVal
;registers modified: none
;NOTE: conversion algorithm based on Lecture 23
;********************************************************
readVal PROC
push ebp                        
mov ebp, esp                    
pushad                                    ;save all registers

getNum:
    mov eax,[ebp + 32]                    ;line number in eax
    push eax                              ;push line num
    push [ebp + 12]                       ;push input string 
    push [ebp + 24]                       ;push output string  
    call writeVal                         ;writeVal writes line num
    displayString [ebp + 28]              ;period and space

    getString [ebp + 12],[ebp + 8]        ;prompt and input string to getString
    mov esi, [ebp + 12]                   ;input string in esi
    mov ecx,0                             ;"x" value        
    jmp checkIfSigned


checkifSigned:
    mov eax,0
    lodsb                                ;load byte of string into al
    cmp al,0                             ;see if it is the last byte
    je total
    cmp al,43                            ;check for plus sign
    je isPos                             ;if so, go to positive conversion
    cmp al,45                            ;see if number is negative
    je isNeg                             ;if so, go to negtive conversion
    cmp al,48                            ;see if number is in range 0-9
    jl badIn            
    cmp al,57                 
    jg badIn                             ;if not, input is bad
    jmp convert                          ;if so, convert number

isPos:
    mov eax,0
    lodsb                                ;load byte of string into al
    cmp al,0                             ;see if it is the last byte
    je total
    cmp al,57                            ;see if number is in range 0-9
    jg badIn            
    cmp al,48                 
    jl badIn                             ;if not, input is bad
    jmp convert                          ;if so, convert number


isNeg:
    mov eax,0
    lodsb                                ;load byte of string into al
    cmp al,0                             ;see if it is the last byte
    je negTotal
    cmp al,57                            ;see if number is in range 0-9
    jg badIn            
    cmp al,48                 
    jl badIn                             ;if not, input is bad
    jmp negCon                           ;if so, convert number
    

negCon:
    sub al, 48                            ;string[k]-48
    mov ebx,eax                           ;string[k]-48 in ebx
    mov eax,ecx                           ;x value in eax
    mov edx,10                            ;multiply by 10
    mul edx
    add eax,ebx                           ;eax = string[k]-48 + x * 10
    mov ecx,eax                           ;put final x value in ecx
    jmp isNeg                             ;back to start

convert:
    sub al, 48                            ;same as above, but checks for overflow                            
    mov ebx,eax                           
    mov eax,ecx                           
    mov edx,10                            
    mul edx
    add eax,ebx                          
    js badIn                              ;if result is signed, it has overflowed
    mov ecx,eax                         
    jmp isPos                          

badIn:
    displayString [ebp + 16]            ;display error message and go back
    call CrLf
    jmp getNum

total:
    mov eax,ecx                        ;final value in eax
    jmp done

negTotal:
    mov eax,ecx                      
    neg eax                             ;negate eax
    jns badIn                           ;if result is a positive number, overflow has happened
    jmp done

done:
    mov ebx,[ebp + 20]                  ;store in array
    mov[ebx],eax
    
popad                                   ;restore registers
pop ebp                
ret 28                
readVal ENDP


;*****************************************************************
;Procedure to fill array
;receives: input string, output string, array, bad input message,
;input prompt message, current number message, running total message,
;period plus space (all by reference), line number, array size
;(by value)
;returns: none
;preconditions: requires displayString macro, calls readVal and
;writeVal
;registers modified: none
;*****************************************************************
fillArray PROC
push ebp
mov ebp,esp
pushad							;save all registers

mov edi,[ebp + 20]              ;array in edi
mov ecx,[ebp + 24]              ;counter = array size 
mov eax,[ebp + 36]              ;line number
mov ebx,0                       ;for adding up numbers

getNums:
push eax
push [ebp + 32]                 ;period plus space
push [ebp + 28]                 ;output string
push edi
push [ebp + 16]                 ;bad input message
push [ebp + 12]                 ;input string
push [ebp + 8]                  ;prompt to get numbers
call readVal
displayString [ebp + 40]        ;"You just entered:"
mov edx,[edi]
push edx                        ;current number and input/output to writeVal
push [ebp + 12]
push [ebp + 28]
call writeVal
call Crlf
displayString [ebp + 44]        ;"The running total is:"
add ebx,[edi]                   ;add to ebx
push ebx                        ;pass running total and input/output to writeVal
push [ebp + 12]
push [ebp + 28]
call writeVal
call Crlf
add edi,4                       ;increment array
inc eax                         ;increment line number
loop getNums


popad							;restore all registers
pop ebp
ret 40
fillArray ENDP


;*****************************************************************
;Procedure to write interger to string
;receives: input string, output string (by reference), value to be
;converted
;returns: none
;preconditions: requires displayString macro
;registers modified: none
;NOTE: flip string algorithm based on demo6 code
;conversion algorithm based on the following Stack Overflow entry:
;https://stackoverflow.com/questions/29065108/masm-integer-to-string-using-std-and-stosb
;*****************************************************************
writeVal PROC
push ebp
mov ebp,esp
pushad								;preserve all registers

mov edi,[ebp + 12]					;input string in edi
mov ecx,0							;counter for digits of string
mov eax,[ebp + 16]					;integer to convert in eax
or eax,eax							;check if eax is positive
jns pConvert
neg eax								;if not, convert to positive
jmp nConvert						;go to negative conversion

nConvert:
mov edx,0							;edx = 0
mov ebx,10							
div ebx								;divide eax by 10	
add edx,48							;add 48 to reaminder to make ASCII digit	
push eax							;preserve eax value
mov eax,edx
stosb								;store in edi
pop eax								;restore eax
inc ecx								;increment counter
cmp eax,0							;if eax != 0, repeat
je nDone
jmp nConvert

nDone:
stosb							    ;store null char in string (string is in reverse)
mov esi,[ebp + 12]				
add esi,ecx						
dec esi							    ;esi is now at end of input string
mov edi,[ebp + 8]				    ;move output string to edi
mov al,45						
mov [edi],al					    ;insert minus sign in edi
inc edi							    ;go to next element of edi
jmp flipString					    ;now, flip input string


pConvert:						    ;same conversion as negative number
mov edx,0
mov ebx,10
div ebx
add edx,48
push eax
mov eax,edx
stosb
pop eax
inc ecx
cmp eax,0
je pDone
jmp pConvert

pDone:
stosb							;store null char in end of string
mov esi,[ebp + 12]
add esi,ecx
dec esi
mov edi,[ebp + 8]				;output string in edi (no minus sign needed)
jmp flipString

flipString:
std								;reverse direction
lodsb							
cld                             ;store characters from end to beginning								
stosb
loop flipString

mov eax,0						;store null char in end of string
stosb

displayString [ebp + 8]			;invoke displayString to show output string 

popad							;restore all registers
pop ebp
ret 12
writeVal ENDP


;***************************************************************
;Procedure to print array
;receives: array title, array, input string, output string, 
;comma and space (all passed by reference)
;returns: none
;preconditions: requires displayString macro, calls writeVal
;registers modified: none
;***************************************************************
printArray PROC
push ebp
mov ebp,esp
pushad									;store all registers

displayString [ebp + 24]				;print array title
mov edi,[ebp + 16]						;array in edi
mov ecx,9								;loop counter

print:
mov eax,[edi]							;move first term to eax
push eax								;send to WriteVal
push [ebp + 12]							;push input and output string
push [ebp + 8]
call writeVal							;write # as string
displayString [ebp + 20]				;print comma and space
add edi,4								;inc edi
loop print									
jmp lastTerm

lastTerm:
mov eax,[edi]							;print final term without comma
push eax
push [ebp + 12]
push [ebp + 8]
call writeVal
call Crlf

popad									;restore all registers
pop ebp
ret 36
printArray ENDP


;*******************************************************************
;procedure to get sum and average
;receives: array, sum  title, average title, input string, output string
;returns: none
;preconditions: requires displayString, calls writeVal
;registers modified: none
;*******************************************************************
calculate PROC
push ebp
mov ebp,esp
pushad

mov edi, [ebp + 24]                         ;number array in edi
mov ecx,10
mov ebx,0                                   ;accumulator for sum
mov eax,0

addAll:
add ebx,[edi]
add edi,4
loop addAll

displayString [ebp + 20]                    ;print sum title
add eax,ebx                                 ;preserve sum in eax
push eax                                    ;push sum to writeVal
push [ebp + 12]
push [ebp + 8]
call writeVal
call Crlf

;get average
displayString [ebp + 16]                    ;title for average
mov eax,ebx                                 ;total sum in eax
mov ebx,10                                  ;number of terms in ebx
cdq                                         ;sign-extend
idiv ebx                                    ;eax/10    
push eax                                    ;push result to writeVal
push [ebp + 12]
push [ebp + 8]
call writeVal
call Crlf

popad
pop ebp
ret 20
calculate ENDP


;*******************************************************************
;procedure to say goodbye to user
;receives: goodbye message (passed by reference)
;returns: none
;preconditions: requires displayString macro
;registers modified: none
;*******************************************************************
byeBye PROC
push ebp
mov ebp,esp

displayString [ebp + 8]                 ;print goodbye message
call Crlf

pop ebp
ret 4
byeBye ENDP

END main