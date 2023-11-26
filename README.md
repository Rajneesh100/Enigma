# Enigma
Enigma was one of the most complex physically made device !

Main idea behind the project is to ensure privacy to the next level !🤷‍♂️ even though now a days all social media applications promises privacy but as long as their is a middle guy their is always a chance of breach so what i thought is :- why not we communicate in encrypted messages over these apps and let our computers do decryption and encryption locally on our devices, no cloud processing! we can share a unique sequence with our friends and can use this encryption very effectively without any privacy related threats👍.
we can simply design a bot to make process fully automated and abstracted( hide all complexities of programming ) to encrypt and  decrypt messages for us.

About the project :  A Program to encrypt messages and decrypt again to generate readable messages and with (if ) knowing initial settings of encryption else spent 4.560057* (10^68) years to get actual settings😎

this projects is meant to encrypt the messages in form of '.'  and ','  and '`'  (we can switch also to any four alphabets or can reduce to 2 or even 1 letters we just have to define one alphabet in terms of others like we can say ',' ='..' and just add a another simple transformation function but it will make regeneration too difficult for us but it's doable).


the heart of the project is the use of ASCII values and their reversed binary representation of each character in form of 1x8x8 matrix and  sequence of letters we have used during encryption and that is the only key to regenerate encrypted message again with the 
help of decription.cpp without that sequence it can't be regenerated by any mean !!

complexity :- ( 30! * 26! * 26! * 10! )

30!-> is for combination of all special characters.

26!-> lower case letters.

26!-> upper case letters.

10!-> digits 0 to 9.

complexity can be made even more tough by combining these all array in one array (max complexity : 92!) 
the current configuration is in simplest form but still will take 4.560057* (10^68) years to decode actual message

Limitations :

  i didn't added options for emojis 🥲, we all know the importance of emojis for showing expressions, But wait we can design a saprate list for emojis also and intresting thing is it's make our encription more tought to crack. 
  there are around more than 500 emojis. if we add let's say k emojis also in our encription programe it will enhance it's complexcity by factor of (K!). so it's + point again.

procedure :

step 1: 
 write down message in message.txt file 

step 2:
 execute encription.cpp
 -> this will generate "encripted.txt" file
 
step 3:
 execute decription.cpp
 -> this will generate "regenerated_message.txt" file
 
 
 




