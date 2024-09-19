// RsaCiel.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "RsaGestion.h"
#include "Hashgestion.h"
#include "AesGestion.h"

int main()
{
	HashGestion LM;
	std::string File = "chat.txt";
	std::cout << LM.CalculateFileSHA256(File) << std::endl;

	AesGestion coco;
	coco.GenerateAESKey();
	coco.SaveAESKeyToFile("aes_random.key");
	coco.EncryptFileAES256("chat.txt", "chatencrypt.txt");
	coco.DecryptFileAES256("chatencrypt.txt", "chatdecrypt.txt");


	return 0;

}


