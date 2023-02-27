/*DOCUMENTATION

Name: AKHIL AJITH K C
Date:30/12/2022
Project:LSB Image Steganography

DOCUMENTATION*/
//preprocessor directives

#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "decode.h"
#include "types.h"


//main function with arguments passed through command line after successful execution returning integer value
int main(int argc, char **argv)
{
    //checking if encoding chosen by user
    if (check_operation_type(argv) == e_encode)
    {
        printf("\nINFO: <---Selected Encoding--->\n");
        EncodeInfo encInfo;            //declaring variable 'encInfo' which is typedef with structure EncodeInfo

        //checking if all arguments are correctly passed through command line for encoding
        if (read_and_validate_encode_args(argv, &encInfo) == e_success)
        {
            printf("INFO: Read and validate is successful\n");
            //checking if Encoding secret data is success or not
            if (do_encoding(&encInfo) == e_success)
            {
                printf("INFO: Encoding completed\n");
            }
            else
            {
                printf("INFO: Failure ---> Encoding is not Done\n");
            }
        }
        else
        {
            printf("INFO: Read and validate was not successful\n");
            return 1;
        }
    }
    //checking if decoding chosen by user
    else if (check_operation_type(argv) == e_decode)
    {
        printf("\nINFO: <---Selected decoding--->\n");
        DecodeInfo decInfo;            //declaring variable 'decInfo' which is typedef with structure DecodeInfo

        //checking if all arguments are correctly passed through command line for decoding
        if (read_and_validate_decode_args(argv, &decInfo) == e_success)
        {
            printf("INFO: Read and validate is successful\n");
            //checking if Decoding secret data is success or not
            if (do_decoding(&decInfo) == e_success)
            {
                printf("INFO: Decoding completed\n\n");
            }
            else
            {
                printf("INFO: Decoding was failure\n");
                return e_failure;
            }
        }
        else
        {
            printf("INFO: Read and validate was not successful\n");
            return e_failure;
        }
    }
    else
    {
        printf("INFO: Invalid input\nPlease pass\nEncoding: ./a.out -e beautiful.bmp secret.txt stego.bmp\nDecoding: ./a.out -d stego.bmp decode.txt\n");    //if arguments are not correctly passed
        return e_failure;
     }
}


//defining function to check if the second argument passed through command line specifies encoding or decoding
OperationType check_operation_type(char *argv[])
{
    //checking if the argument is for encoding 
    if ((strcmp(argv[1],"-e")) == 0)
    {
        return e_encode;               //start to perform encoding
    }
    //checking if the argument is for decoding 
    else if ((strcmp(argv[1], "-d")) == 0)
    {
        return e_decode;               //start to perform decoding
    }
    else
    {
        return e_unsupported;          //invalid
    }
}

