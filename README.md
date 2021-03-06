Travis Identifier [![License][license-img]][license-url]
=
Simple Travis example for C using GCC compiler based on the identifier program presented by Delamaro et al. "Introdução ao Teste de Software". Elsevier. 2007.

Test results:

[<img alt="Build Status" src="https://api.travis-ci.com/renanbmx123/TF_TCS.svg?branch=master" height="40">][travis-url]

Important files:

* [identifier.c](identifier.c)
* [Makefile](Makefile)
* [.travis.yml](.travis.yml)


Author
------
[**Renan Alves**](https://www.linkedin.com/in/renan-alves-2950a884/)


### INFORMAÇÕES GERAIS

O objetivo desse trabalho é utilizar na prática os conceitos e ferramentas de teste de software estudados durante o semestre.
- Pontuação:Essa avaliação vaivaler 50% da minha parte da nota.
- Entrega:23/06/2021, 17:30 (Hard deadline) 
- Trabalho pode ser realizado sozinho ou em dupla, sem possibilidade de uma configuração diferente.

### ESPECIFICAÇÃO DO PROBLEMA

No mundo cada vez mais tecnológico que estamos vivendo, a segurança é uma das nossas maiores preocupações e muitos aspectos como segurança da informação, confidencialidade e integridade dos dados são temas recorrentes encontrados. Neste sentido, <b>o trabalho de vocês visa garantir que um programa de criptografia não apresente defeitos</b>. Portanto, vocês devem criar casos de testes para um programa que criptografa uma mensagemde 128-bits implementado a partir de 3 algoritmos de criptografia (XTEA, AESe Blowfish). <br/>Note que os algoritmos de criptografia suportados são simétricos, isto é, ele utiliza uma chave única para cifrar e decifrar a mensagem.Abaixo é mostrado a definição do programa:

```void crypt(uint32_t* key, uint32_t* input, uint8_t type, uint8_t enc_dec, uint32_t* output);```

A função cryptrecebe 5 argumentos, o key é um ponteiro para a chave criptográfica que pode ter 128-bits, 192-bits ou 256-bits. Neste sentido, como a estrutura básica é de 32-bits, teremos respectivamente, 4, 6 ou 8 elementos que constituem o key. O input é a mensagem a ser criptografada e que tem 128-bits, logo, como segue a mesma estrutura de 32-bits, esse argumento é um ponteiro. O type indica qual versão do algoritmo é utilizado, onde: 0 = XTEA; 1= AES-128; 2= AES-192; 3= AES-256;4= BLOWFISH-128; 5= BLOWFISH-192; e 6= BLOWFISH-256. Já o argumento enc_dec indica codificação ou decodificação, onde: 1 = codificação (encoder); e 2 = decodificação (decoder).Por fim, o argumento output é a mensagem cifrada de 128-bits, e similarmente ao input, este argumento também é um ponteiro. <br/> Os algoritmos suportados pela função crypt são descritos abaixo, mas como eles são conhecidos e largamente utilizados, mais informações podem ser encontradasna internet.

- XTEA:é um bloco de 64-bits de rede Feistel com uma chave de 128-bits e que executam por diversas rodadas, sugere-se 64. Neste sentido, a criptografia aplica-se ciclicamente em toda uma mensagem por várias iterações. Ele já foi utilizado em vídeo games da Microsoft.

- AES:algoritmo selecionado e que se tornou padrão do governo dos Estados Unidos para substituir o DES. Atualmente, é um dos algoritmos de criptografia mais utilizados mundialmente. Ele é confiável e bastante eficiente na sua forma em 128-bits, mas também é possível usar chaves e 192 e 256-bits para informações que precisam de proteção maior.

- Blowfish:foi outro algoritmo desenvolvido para substituir o DES. É um algoritmo simétrico que divide as informações em blocos de 64-bits e criptografa cada um deles individualmente. De forma geral, o Blowfishé usado em plataformas de e-commerce para garantir segurança nos pagamentos e proteger senha de acesso dos usuários. Nesta implementação, ele utiliza uma variação do Twofish, onde a diferença é que ele é formado por blocos de 128-bits e chaves de até 256 bits.

### RECURSOS UTILIZADOS 

Vocês devem utilizar como base o seguinte projeto: [Git TCS-TF-2021-1](https://github.com/rafaelgaribotti/TCS-TF-2021-1). Este projeto usa gcc como compilador,make para automatizar a compilação, e deve usar o Travis CI como ferramenta de Continuous Integration. Além disso, vocês devem utilizar também ogcovcomo ferramenta de análise de cobertura de código, além das seguintes ferramentas voltas a teste:cppcheck,valgrindesanitizer.Também devem usar uma ferramenta para descrever os testes. Eu sugiro o uso do nity, já mostrado em aula, mas este ponto fica de livre escolha caso alguns grupos queiram pesquisar e usar outras ferramentas. Neste sentido, deixo a critério do grupo decidir qual ferramenta utilizar para este propósito. Algumas alternativas mais conhecidas incluem:gtest,cpptest,catch. Entretanto existem dezenas de outras opções.Os alunos podem propor ferramentas adicionaise isso vai ser altamente valorizado na avaliação.

### ENTREGÁVEIS
- Um arquivo zip com o código fonte do repositório eo relatório, ambos postados no Moodle ANTES do prazo. 
- Os grupos devem se identificar peloFórum do Moodle.
- Os grupos terão queapresentaro seu ambiente de projeto, seus testes e os resultados.
- O repositório deve ser totalmente automatizado com make em termos de: compilação, execução do relatório de cobertura, e execução dos testes. A cada commit o Travis CI deve ser executado para verificar se os testes passaram.
- O relatóriodeve ser no formado PDF, e conter: Uma tabela com as classes de equivalências e valores limites e os testes resultantes do uso destes 2 critérios. Ao descrever os testes no relatório, especifiquem no seguinte formato:

| Número do Teste| Nome do Teste| Casos de Teste | 
|----------------|--------------|----------------|
| 1 | <nome do teste1> | [{entrada},{saida esperada}] |
| 2 | <nome do teste2> | [{entrada},{saida esperada}] |
| ...| ...| ... |
| N |<nome do testeN>| [{entrada},{saida esperada}] |

- Especifiquem separadamente os testes adicionais, por exemplo, testes incluídospara aumentar a cobertura de código. Neste caso, além de adotar o mesmo formato paradescrever  o  teste,  inclua  também  uma  frase  justificando  a  inclusão  desse  teste.  Por exemplo, ele cobre que parte do código? Que caso relevante que vocêsperceberam que é necessário,mas que os critérios de equivalência e valor limite não contemplavam?
- Cobertura: o gcovsuporta cobertura de linhas e de branch, mas é recomendado que também considerem cobertura de caminhoe cobertura depredicados. Paraa cobertura depredicados, usem a técnica que mostrei em aula paramontar a tabela verdade e definir quais os testes devem ser incluídos. Inclua os resultados obtidos de cobertura no relatório

- Incluam no relatórioas ferramentas adicionais de verificaçãoutilizadas, se este for o caso. 
- Evitem modificações no código fonte original. Mudanças pequenas e pontuais são permitidas com o intuito de facilitar a execução do teste. Tais mudanças se ocorrerem, devem ser relatadas no código fonte com comentários e também no relatório.

### AVALIAÇÃO 
- [3 pontos] Relatório e apresentação 
- [2 pontos] Automaçãodos scripts 
- [3 pontos] Qualidade e completude dos testes 
- [2 pontos] Uso adequado das ferramentas indicadas PS.: A apresentação é obrigatória!Logo, a não apresentação do trabalho será considerado como <b>trabalho não entregue.</b>

License
-------
MIT License. See [LICENSE](LICENSE) for details.

[main-url]: https://github.com/renanbmx123/TF_TCS
[readme-url]: https://github.com/renanbmx123/TF_TCS/blob/main/README.md
[license-url]: https://github.com/renanbmx123/TF_TCS/blob/main/LICENSE
[license-img]: https://img.shields.io/github/license/rsp/travis-hello-modern-cpp.svg
[travis-url]: https://www.travis-ci.com/renanbmx123/TF_TCS
[travis-img]: https://www.travis-ci.com/renanbmx123/TF_TCS.svg?branch=master
[github-follow-url]: https://github.com/renanbmx123
