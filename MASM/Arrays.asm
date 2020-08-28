TITLE Program 5     (Addiego_Emily_program5.asm)

; Author: Emily Addiego
; Last Modified: 2/18/2020
; OSU email address: addiegoe@oregonstate.edu
; Course Number/section: 271/400
; Project number: 5            Due Date: 3/1/2020
; Description: This program uses procedures with parameters
; passed on the system stack to create an array of random
; numbers 10-29, count the instances of each number,
; sort the array, and calculate the median.

INCLUDE Irvine32.inc

ARRAYSIZE = 200
HI = 29
LO = 10
COUNTSIZE = 20
.data
array	DWORD	ARRAYSIZE DUP(?)
counts	DWORD	20 DUP(?)
pName	BYTE    "Sorting and Counting Random Integers by Emily Addiego",0
desc	BYTE	"This program generates 200 random numbers between 10 and 29, counts the occurrence of each number, sorts the array by count, and displays all arrays plus the median of the sorted array.",0
EC1		BYTE	"**EC: This program counts before sorting the array.",0
title1	BYTE	"Unsorted array:",0
title2	BYTE	"Count of how many times each number occurs, starting with 10:",0
title3	BYTE    "Sorted array:",0
title4	BYTE	"Median: ",0
space	BYTE	"  ",0
bye		BYTE	"That's it! Goodbye!",0


.code
main PROC
	call Randomize				;randomize numbers
	push OFFSET pName
	push OFFSET desc
	push OFFSET EC1
	call introduction			;call each procedure in order	
	call Crlf
	push LO
	push HI
	push OFFSET array
	push ARRAYSIZE
	call fillArray	
	push OFFSET space
	push OFFSET title1
	push OFFSET array
	push ARRAYSIZE
	call displayList
	call Crlf
	push LO
	push OFFSET counts
	push OFFSET array
	push ARRAYSIZE
	call countList
	push OFFSET space
	push OFFSET title2
	push OFFSET counts
	push COUNTSIZE
	call displayList
	call Crlf
	push OFFSET array
	push OFFSET counts
	push LO
	call sortList
	push OFFSET title4
	push OFFSET array
	push ARRAYSIZE
	call displayMedian
	call Crlf
	push OFFSET space
	push OFFSET title3
	push OFFSET array
	push ARRAYSIZE
	call displayList


call Crlf
mov edx,OFFSET bye
call WriteString
call Crlf


exit							;exit to OS

main ENDP						;end of main


;*********************************************************
;Procedure to display the title and description of program
;receives: program name, description, EC messages (passed by reference)
;returns: none
;preconditions: none
;registers changed: edx
;*********************************************************
introduction PROC
push ebp						;set up stack frame
mov ebp,esp					
mov edx,[ebp + 16]				;edx = @ program name
call WriteString				;print program name
call Crlf
call Crlf
mov edx,[ebp + 12]				;description
call WriteString				;print description
call Crlf
mov edx,[ebp + 8]				;EC
call WriteString				;print EC
call Crlf
pop ebp
ret 12
introduction ENDP


;*********************************************************
;Procedure to fill array with random numbers [10-29]
;receives: array(reference), LO, HI, ARRAYSIZE
;returns: none
;preconditions: none
;registers changed: eax, edi, ecx
;NOTE: modeled after procedures in Lectures 19 and 20
;*********************************************************
fillArray PROC
push ebp
mov ebp,esp
mov edi,[ebp + 12]			;store array reference in edi
mov ecx,[ebp + 8]			;store array size in counter

L1:
mov eax,[ebp + 16]			;29 in eax
sub eax,[ebp + 20]			;29-10 = 19
inc eax						;20
call RandomRange			;random number 0-20
add eax,[ebp + 20]			;add LO
mov [edi],eax				;move eax into address at edi
add edi,4					;increment edi
loop L1						;go back to start

pop ebp
ret 16
fillArray ENDP


;********************************************************
;Procedure to display title of array and print array
;receives: array(reference), array size, title
;returns: none
;preconditions: array has been filled
;registers modified: edx, eax, ecx, ebx, esi
;NOTE: modeled after display procedure in Lecture 20
;********************************************************
displayList PROC
push ebp
mov ebp,esp
mov edx,[ebp + 16]			;print list title
call WriteString
call Crlf
mov esi,[ebp + 12]			;@ array
mov ecx,[ebp + 8]			;array size in counter
mov ebx,1					;term counter

print:
mov eax,[esi]				;get current term
call WriteDec				;print
mov edx,[ebp + 20]			;print space
call WriteString
add esi,4					;increment
inc ebx
cmp ebx,21					;check number of terms
je newLine
jmp goBack

newLine:
call Crlf					;add a new line
mov ebx,1
jmp goBack

goBack:
loop print					;go back to start

pop ebp
ret 16
displayList ENDP


;*******************************************************
;Procedure to count occurrences of each number in list
;receives: array(reference), counts(reference),
;ARRAYSIZE, LO
;returns: none
;preconditions: array has been filled
;registers modified: edi, esi, eax, ebx, ecx, edx
;********************************************************
countList PROC 
push ebp
mov ebp,esp
mov edi,[ebp + 16]		;counts array
mov eax,[ebp + 20]		;LO value
mov ebx,0

top:
mov esi,[ebp + 12]      ;original array
mov ecx,[ebp + 8]		;inner loop -- arraysize
mov edx,0				;term counter
jmp L2

L2:
cmp eax,[esi]			;compare value to value @ esi
je addUp				;if equal, add to count
jmp goBack				;if not, loop back

addUp:
inc edx					;increment count
jmp goBack

goBack:
add esi,4				;increment address of esi by 4
loop L2					;go back

mov [edi],edx			;store count in edi
add edi,4				;increment edi
inc eax					;increase number searched for
inc ebx
cmp ebx,20				;if count is at 20, stop
je bottom
jmp top

bottom:
pop ebp
ret 16
countList ENDP


;********************************************************
;Procedure to sort array using a counted sort
;receives: array(reference), counts(reference), LO(value)
;returns: none
;preconditions: countList has been called
;registers modified: eax, edx, ebx, esi, edi, ecx
;Note: algorithm based on rosettacode.org/wiki/sorting_algorithms/Counting_sort
;*********************************************************
sortList PROC
push ebp
mov ebp,esp

mov edx,[ebp + 8]			;LO in eax
mov esi,[ebp + 12]			;@counts in esi
mov edi,[ebp + 16]			;@array in edi	
mov ebx,0	

start:
mov eax,[esi]			;move value at esi into eax
cmp eax,0				;make sure value is not 0
je newStart
mov ecx,[esi]			;move value at esi into ecx
jmp L1

newStart:
inc ebx					;make sure not beyond last term
cmp ebx,10
je finished
add esi, 4				;increment esi
inc edx					;increment value
jmp start				;go back

L1:
mov [edi],edx			;push value into edi according to counts
add edi,4
loop L1

inc ebx					;check for end of array
cmp ebx,20
je finished
inc edx					;increment value
add esi,4				;increment esi
jmp start				;go back


finished:
pop ebp
ret 12
sortList ENDP

displayMedian PROC
push ebp
mov ebp,esp
mov edx,[ebp + 16]		;print title
call WriteString

mov esi,[ebp + 12]		;@array in esi
mov eax,[ebp + 8]		;arraysize in eax
cdq
mov ebx,2
div ebx					;half of arraysize in eax

mov ebx,4	
mul ebx					;multiply by 4 to get correct index

mov ebx,eax				;400 in ebx
mov eax,[esi + ebx]		;100th term in eax
add ebx,4
mov edx,[esi + ebx]		;101st term in edx
cmp eax,edx
jle roundDown			;if 100 <= 101, round down
add eax,1				;else, round up

roundDown:
call WriteDec			;value in eax
call Crlf

pop ebp
ret 12
displayMedian ENDP



END main

