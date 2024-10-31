
# Controle de fluxo básico 🔁
<div style="display: inline_block"><br>

## Tecnlogia utilizada
  <img align="center" alt="Rafa-Js" height="40" width="50"
     src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/c/c-original.svg" />
        
</div>
<br>

## Descrição
Trabalho simples de estoque e fluxo realizado na faculdade, na matéria de estrutura de dados!
<p>Realizado utilizando apenas linguagem C</p>

<br>
<br>

## Proposta do exercício 📝


Uma revendedora de produtos naturais contratou você para fazer um programa de controle de estoque de suas mercadorias. O programa deve permitir o cadastro e consulta aos itens e sua venda.
<br>

### Observações:
<ul>
  <li>O cadastro de clientes será necessário para compras parceladas e deve conter os seguintes dados: nome, CPF, endereço (rua, número, bairro, CEP, complemento), telefone e data de nascimento. Não podem haver clientes duplicados.</li>
  
  <br>
  
  <li>O cadastro de clientes e produtos deve ser realizado enquanto houver espaço na(s) estrutura(s) de armazenamento escolhida. Determine a quantidade/tamanho da(s) estrutura(s) de armazenamento. 
  Não pode haver produtos duplicados em estoque. Produtos devem ter os seguintes campos: código, nome/descrição, valor, validade.</li>

  <br>
  
  <li>A venda de produtos deve incluir baixa no estoque, cálculo total da compra, formas de pagamento e cálculo do troco.</li>

  <br>
  
  <li>A baixa no estoque só poderá ser realizada mediante pagamento, ou seja, dê baixa apenas após concluir a venda.</li>

  <br>
  
  <li>Formas de pagamento incluem: à vista, com 10% de desconto; parcelamento em 3X, no valor da compra; parcelamento de 4X a 6X, com juros de 10% sobre o valor total da compra.</li>

  <br>
  
  <li>Forneça as seguintes buscas/consultas: produtos cadastrados; produtos com X dias da data de vencimento; produtos vencidos em estoque; clientes cadastrados; total de vendas realizadas nos últimos X dias; quantidade em estoque de determinado produto.</li>

  <br>
  
  <li>Faça todas as validações necessárias para o bom funcionamento do programa. Procure otimizar seu código em termos de seleção das estruturas de dados mais apropriadas, de acessos à memória, processamento e estrutura e legibilidade do código.</li>

  <br>
  
  <li>Opções do menu: 1. cadastro de clientes; 2. cadastro de produtos; 3. consultas (com menu interno para os tipos possíveis); 4. venda; 5. baixa em estoque (p. ex. para produtos vencidos) e 6. Encerrar.</li>
</ul>

<br>
<br>

## Implementação (ideia) 💡
Através de duas structs e as determinadas funções especificadas na proposta do exercício, são realizadas todas as funcionalidades que o programa exige!
<p>Utilizo a biblioteca time.h para pegar a data atual e verificar produtos em vencimento e produtos com X dias para vencer. Além das bibliotecas string.h e strings.h para utilizar funções como "strcmp" (cusada para comparar duas strings) e da biblioteca padrao stdio.h!</p>

