/*
**  Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> 
**  Include Files 
*/
#include "ring.h"
#include "ring_vmopenssl.h"
#include "openssl/md5.h"
#include "openssl/sha.h"
#include "openssl/evp.h"
#include "openssl/rand.h"
#include "ring_vmopenssl.h"
/* Functions */

RING_API void ringlib_init ( RingState *pRingState )
{
	ring_vm_funcregister("md5",ring_vm_openssl_md5);
	ring_vm_funcregister("sha1",ring_vm_openssl_sha1);
	ring_vm_funcregister("sha256",ring_vm_openssl_sha256);
	ring_vm_funcregister("sha512",ring_vm_openssl_sha512);
	ring_vm_funcregister("sha384",ring_vm_openssl_sha384);
	ring_vm_funcregister("sha224",ring_vm_openssl_sha224);
	ring_vm_funcregister("encrypt",ring_vm_openssl_encrypt);
	ring_vm_funcregister("decrypt",ring_vm_openssl_decrypt);
	ring_vm_funcregister("randbytes",ring_vm_openssl_randbytes);
}

void ring_vm_openssl_md5 ( void *pPointer )
{
	unsigned char digest[MD5_DIGEST_LENGTH]  ;
	char cString[33]  ;
	int x,nSize  ;
	char *cInput  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cInput = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		MD5((unsigned char *) cInput, nSize, (unsigned char *) &digest);
		for ( x = 0 ; x < 16 ; x++ ) {
			sprintf( &cString[x*2] , "%02x" , (unsigned int) digest[x] ) ;
		}
		RING_API_RETSTRING(cString);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_openssl_sha1 ( void *pPointer )
{
	unsigned char digest[SHA_DIGEST_LENGTH]  ;
	char cString[SHA_DIGEST_LENGTH*2+1]  ;
	int x,nSize  ;
	char *cInput  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cInput = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		SHA1((unsigned char *) cInput, nSize, (unsigned char *) &digest);
		for ( x = 0 ; x < SHA_DIGEST_LENGTH ; x++ ) {
			sprintf( &cString[x*2] , "%02x" , (unsigned int) digest[x] ) ;
		}
		RING_API_RETSTRING(cString);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_openssl_sha256 ( void *pPointer )
{
	unsigned char digest[SHA256_DIGEST_LENGTH]  ;
	char cString[SHA256_DIGEST_LENGTH*2+1]  ;
	int x,nSize  ;
	char *cInput  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cInput = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		SHA256((unsigned char *) cInput, nSize, (unsigned char *) &digest);
		for ( x = 0 ; x < SHA256_DIGEST_LENGTH ; x++ ) {
			sprintf( &cString[x*2] , "%02x" , (unsigned int) digest[x] ) ;
		}
		RING_API_RETSTRING(cString);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_openssl_sha512 ( void *pPointer )
{
	unsigned char digest[SHA512_DIGEST_LENGTH]  ;
	char cString[SHA512_DIGEST_LENGTH*2+1]  ;
	int x,nSize  ;
	char *cInput  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cInput = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		SHA512((unsigned char *) cInput, nSize, (unsigned char *) &digest);
		for ( x = 0 ; x < SHA512_DIGEST_LENGTH ; x++ ) {
			sprintf( &cString[x*2] , "%02x" , (unsigned int) digest[x] ) ;
		}
		RING_API_RETSTRING(cString);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_openssl_sha384 ( void *pPointer )
{
	unsigned char digest[SHA384_DIGEST_LENGTH]  ;
	char cString[SHA384_DIGEST_LENGTH*2+1]  ;
	int x,nSize  ;
	char *cInput  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cInput = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		SHA384((unsigned char *) cInput, nSize, (unsigned char *) &digest);
		for ( x = 0 ; x < SHA384_DIGEST_LENGTH ; x++ ) {
			sprintf( &cString[x*2] , "%02x" , (unsigned int) digest[x] ) ;
		}
		RING_API_RETSTRING(cString);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_openssl_sha224 ( void *pPointer )
{
	unsigned char digest[SHA224_DIGEST_LENGTH]  ;
	char cString[SHA224_DIGEST_LENGTH*2+1]  ;
	int x,nSize  ;
	char *cInput  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cInput = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		SHA224((unsigned char *) cInput, nSize, (unsigned char *) &digest);
		for ( x = 0 ; x < SHA224_DIGEST_LENGTH ; x++ ) {
			sprintf( &cString[x*2] , "%02x" , (unsigned int) digest[x] ) ;
		}
		RING_API_RETSTRING(cString);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_openssl_encrypt ( void *pPointer )
{
	unsigned char *in, *out, *key, *iv  ;
	int nSize,buflen, tmplen, nSize2  ;
	EVP_CIPHER_CTX ctx  ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) && RING_API_ISSTRING(2) && RING_API_ISSTRING(3) ) {
		in = (unsigned char *) RING_API_GETSTRING(1) ;
		key = (unsigned char *) RING_API_GETSTRING(2) ;
		iv = (unsigned char *) RING_API_GETSTRING(3) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		out = (unsigned char *) malloc(nSize*2) ;
		EVP_CIPHER_CTX_init(&ctx);
		EVP_EncryptInit_ex(&ctx, EVP_bf_cbc(), NULL, key, iv);
		if ( !EVP_EncryptUpdate(&ctx, out, &buflen, in, nSize) ) {
			free( out ) ;
			return ;
		}
		if ( !EVP_EncryptFinal_ex(&ctx, out + buflen, &tmplen) ) {
			free( out ) ;
			return ;
		}
		nSize2 = buflen + tmplen ;
		RING_API_RETSTRING2((const char *) out,nSize2);
		EVP_CIPHER_CTX_cleanup(&ctx);
		free( out ) ;
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_openssl_decrypt ( void *pPointer )
{
	unsigned char *in, *out, *key, *iv  ;
	int nSize,buflen, tmplen, nSize2  ;
	EVP_CIPHER_CTX ctx  ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) && RING_API_ISSTRING(2) && RING_API_ISSTRING(3) ) {
		in = (unsigned char *) RING_API_GETSTRING(1) ;
		key = (unsigned char *) RING_API_GETSTRING(2) ;
		iv = (unsigned char *) RING_API_GETSTRING(3) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		out = (unsigned char *) malloc(nSize*2) ;
		EVP_CIPHER_CTX_init(&ctx);
		EVP_DecryptInit_ex(&ctx, EVP_bf_cbc(), NULL, key, iv);
		if ( !EVP_DecryptUpdate(&ctx, out, &buflen, in, nSize) ) {
			free( out ) ;
			return ;
		}
		if ( !EVP_DecryptFinal_ex(&ctx, out + buflen, &tmplen) ) {
			free( out ) ;
			return ;
		}
		nSize2 = buflen + tmplen ;
		RING_API_RETSTRING2((const char *) out,nSize2);
		EVP_CIPHER_CTX_cleanup(&ctx);
		free( out ) ;
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_openssl_randbytes ( void *pPointer )
{
	unsigned char *cStr  ;
	int nNum1  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		nNum1 = (int) RING_API_GETNUMBER(1) ;
		if ( nNum1 > 0 ) {
			cStr =  malloc(nNum1+1) ;
			if ( RAND_bytes(cStr,nNum1) ) {
				RING_API_RETSTRING2((const char *) cStr,nNum1);
			}
			else {
				RING_API_RETNUMBER(0);
			}
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
