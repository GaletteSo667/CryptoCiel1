#include <iostream>
#include "RsaGestion.h"
#include "Hashgestion.h"
#include "AesGestion.h"

int main()
{
    // **Gestion du Hashing (SHA-256)**
    HashGestion LM;
    std::string File = "chat.txt";
    std::cout << "SHA-256 du fichier '" << File << "' : " << LM.CalculateFileSHA256(File) << std::endl;

    // **Gestion AES**
    AesGestion coco;
    coco.GenerateAESKey();
    coco.SaveAESKeyToFile("aes_random.key");

    // Chiffrement du fichier avec AES-256
    std::cout << "Chiffrement du fichier avec AES-256...\n";
    coco.EncryptFileAES256("chat.txt", "chatencrypt.txt");

    // Déchiffrement du fichier avec AES-256
    std::cout << "Déchiffrement du fichier avec AES-256...\n";
    coco.DecryptFileAES256("chatencrypt.txt", "chatencrypt_decrypted.txt");

    // **Gestion RSA**
    RsaGestion rsaGestion;

    // Génération des clés RSA
    std::cout << "\nGénération des clés RSA...\n";
    rsaGestion.generationClef("rsa_public.key", "rsa_private.key", 2048);

    // Message à chiffrer
    std::string message = "Message secret à chiffrer avec RSA";
    std::cout << "\nMessage original : " << message << std::endl;

    // Chiffrement du message avec RSA
    std::string messageChiffre = rsaGestion.chiffrementRsa(message);
    std::cout << "Message chiffré : " << messageChiffre << std::endl;

    // Déchiffrement du message avec RSA
    std::string messageDechiffre = rsaGestion.dechiffrementRsa(messageChiffre);
    std::cout << "Message déchiffré : " << messageDechiffre << std::endl;

    return 0;
}
