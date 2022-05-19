# Infra_software4
Atividade para obtenção de nota parcial da cadeira "Infraestrutura de Software"

## Como clonar o repositório:
```bash
$ git clone https://github.com/ElderLamarck/infra_software_tutoria4.git
$ cd infra_software_tutoria4
```

## Como utilizar o programa:
O diretorio possui um arquivo makefile, nele existem os comandos run e clean, para compilar é necessario usar o "make" e em seguida "make run" para rodar. O programa consiste de 2 grupos de threads um grupo chamado de produtor e outro chamado de consumidor. O grupo de produção executam uma função e retornam um valor para o Buffer e lá o segundo grupo atua varendo o buffer e recolhendo os valores criados.
