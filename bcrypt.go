package main

import (
	"C"

	"golang.org/x/crypto/bcrypt"
)

//export Encrypt
func Encrypt(input *C.char) *C.char {
	str := []byte(C.GoString(input))

	res, err := bcrypt.GenerateFromPassword(str, bcrypt.DefaultCost)

	if err != nil {
		panic(err)
	}

	return C.CString(string(res))
}

//export Compare
func Compare(hash *C.char, plainText *C.char) *C.char {
	hashed, plain := []byte(C.GoString(hash)), []byte(C.GoString(plainText))
	err := bcrypt.CompareHashAndPassword(hashed, plain)

	if err != nil {
		return C.CString("false")
	}

	return C.CString("true")
}

func main() {}
