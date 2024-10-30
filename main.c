#include <stdio.h>
#include <stdbool.h>
#include <string.h>   
#define MAX 5


    struct usuario
    {
        int cpf;
        char nome[20];
        char endereco[120];
        int tel;
        char nascimento[11];
    };

   struct produto
    {
        int codigo;
        char nome[20];
        float valor;
        char validade[11];
        int quantidade;
    };

    typedef struct usuario Cliente;
    typedef struct produto Item;

    void criarCliente(Cliente usuario[], int *cont_cliente);
    void criarProduto(Item produto[], int *cont_produto);
    void consultarPessoa(Cliente usuario[], int cont_cliente);
    void consultarProduto(Item usuario[], int cont_produto, float *total_vendas);
    bool verificaCliente(Cliente usuario[], int cont_cliente, int cpf);
    bool verificaProduto(Item produto[], int cont_produto, int codigo);
    void realizarVenda(Item produto[], int *cont_produto, float *total_venda);
    void baixaEstoque(Item produto[], int codigo, int quantidade);
    void consultarTotalVendas(float totalVendas);















int main(){
    int opcao;

    Cliente pessoas[MAX];
    Item produto[MAX];
    int cont_cliente = 0;
    int cont_produto = 0;
    int tipo_consulta;
    int codigo, qtd;
    float total_venda = 0.0;
    



    do{
        printf("Menu:\n 1. cadastro de clientes\n 2. cadastro de produtos\n 3. consultas\n 4. venda\n 5. baixa em estoque\n 6. Encerrar\n");
        printf("Digite sua escolha:\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            criarCliente(pessoas, &cont_cliente);
            break;
        case 2:
            criarProduto(produto, &cont_produto);
            break;
        case 3:
            printf("\nDigite:\n1. Caso queira consultar pessoas\n2. Caso queira consultar produtos\n");
            scanf("%d", &tipo_consulta);
            if(tipo_consulta == 1){
                consultarPessoa(pessoas, cont_cliente);
            }else{
                consultarProduto(produto, cont_produto, &total_venda);
            }
            break;
        case 4:
            realizarVenda(produto, &cont_produto, &total_venda);
            break;
        case 5:
            
            printf("Digite o codigo do produto:");
            scanf("%d", &codigo);
            printf("Digite a quantidade a dar baixa:");
            scanf("%d", &qtd);

            baixaEstoque(produto, codigo,qtd);
        case 6:
            break;
        }
    }while(opcao > 0 && opcao <= 5);
}





//Escolha 1
void criarCliente(Cliente usuario[], int *cont_cliente){    
    if(*cont_cliente <= MAX){
        int cpf;

        printf("\nDigite o nome:");
        scanf(" %s", usuario[*cont_cliente].nome);

        printf("Digite o CPF:");
        scanf("%d", &cpf);

        if(verificaCliente(usuario, *cont_cliente, cpf)){

            printf("\nUsuario ja cadastrado!\n\n");
        
        }else{
            usuario[*cont_cliente].cpf = cpf;
        
            printf("Digite o endereço:");
            scanf(" %s", usuario[*cont_cliente].endereco);

            printf("Digite o telefone:");
            scanf("%d", &usuario[*cont_cliente].tel);

            printf("Digite a data de nascimento:");
            scanf(" %s", usuario[*cont_cliente].nascimento);

            (*cont_cliente)++;
            printf("\n");
        }

    }else{
        printf("\nNumero maximo de Usuarios atingidos!\n\n");
    }
    
}

//Escolha 2
void criarProduto(Item produto[], int *cont_produto){
    if(*cont_produto <= MAX){
        int codigo;

        printf("\nDigite o codigo do produto:");
        scanf("%d", &codigo);

        if(verificaProduto(produto, *cont_produto, codigo)){

            printf("\nProduto ja cadastrado!\n\n");

        }else{
            produto[*cont_produto].codigo = codigo;

            printf("Digite o nome do produto:");
            scanf(" %s", produto[*cont_produto].nome);

            printf("Digite o valor do produto:");
            scanf("%f", &produto[*cont_produto].valor);

            printf("Digite a validade do produto:");
            scanf(" %s", produto[*cont_produto].validade);

            printf("Digite a quantidade do produto:");
            scanf("%d", &produto[*cont_produto].quantidade);
            (*cont_produto)++;
            printf("\n");
        }
    }else{
        printf("\nNumero Maximo de Produtos atingido!\n\n");
    }
}





bool verificaCliente(Cliente usuario[], int cont_cliente, int cpf){
    bool eh_repetido = false;

    for(int i = 0; i < cont_cliente; i++){
        if(usuario[i].cpf == cpf){
            eh_repetido = true;
        }
    }

    return eh_repetido;
}




bool verificaProduto(Item produto[], int cont_produto, int codigo){
    bool eh_repetido = false;

    for(int i = 0; i < cont_produto; i++){
        if(produto[i].codigo == codigo){
            eh_repetido = true;
        }
    }

    return eh_repetido;
}




//Escolha 3
void consultarProduto(Item produto[], int cont_produto, float *total_vendas){
    printf("Caso queira consultar por:\n1. Codigo digite\n2. Nome digite\n3. Valor digite\n4. Validade digite\n5. Produtos vencidos\n6. Total de vendas\n\n");
    int tipo_consulta, codigo;
    char nome[30];
    char validade[11];
    float valor;
    scanf("%d", &tipo_consulta);

    switch (tipo_consulta)
    {
    case 1:
        printf("Digite o código: ");
        scanf("%d", &codigo);
        bool encontrado = false;
        for(int i = 0; i < cont_produto; i++){
            if(produto[i].codigo == codigo && produto[i].quantidade > 0){
                printf("Produto encontrado:\nCódigo: %d\nNome: %s\nValor: %.2f\nValidade: %s\nQuantidade: %d\n\n", produto[i].codigo, produto[i].nome, produto[i].valor, produto[i].validade, produto[i].quantidade);
                encontrado = true;
            }
        }
        if(encontrado == false){
            printf("Produto nao encontrado ou sem estoque\n\n");
        }
        break;
    case 2:{
        printf("Digite o nome: ");
        scanf(" %s", nome);
        bool encontrado = false;
        for(int i = 0; i < cont_produto; i++){
            if(strcmp(produto[i].nome, nome) == 0 && produto[i].quantidade > 0){
                 printf("Produto encontrado:\nCódigo: %d\nNome: %s\nValor: %.2f\nValidade: %s\nQuantidade: %d\n", produto[i].codigo, produto[i].nome, produto[i].valor, produto[i].validade, produto[i].quantidade);
                 encontrado = true;
            }
        }
        if(encontrado == false){
            printf("Produto nao encontrado\n\n");
        }
        break;
    }
    case 3:{
        printf("Digite o valor: ");
        scanf("%f", &valor);
        bool encontrado = false;
        for(int i = 0; i < cont_produto; i++){
            if(produto[i].valor == valor && produto[i].quantidade > 0){
                 printf("Produto encontrado:\nCódigo: %d\nNome: %s\nValor: %.2f\nValidade: %s\nQuantidade: %d\n", produto[i].codigo, produto[i].nome, produto[i].valor, produto[i].validade, produto[i].quantidade);
                 encontrado = true;
            }
        }
        if(encontrado == false){
            printf("Produto nao encontrado\n\n");
        }
        break;
    }
    case 4:{
        printf("Digite a validade: ");
        scanf(" %s", validade);
         bool encontrado = false;
        for(int i = 0; i < cont_produto; i++){
            if (strcmp(produto[i].validade, validade) == 0 && produto[i].quantidade > 0) {
                 printf("Produto encontrado:\nCódigo: %d\nNome: %s\nValor: %.2f\nValidade: %s\nQuantidade: %d\n", produto[i].codigo, produto[i].nome, produto[i].valor, produto[i].validade, produto[i].quantidade);
                 encontrado = true;
            }
        }
        if(encontrado == false){
            printf("Produto nao encontrado\n\n");
        }
        break;
    } 
    /*case 5:{ 
        printf("Produtos vencidos:\n");
        bool encontrado = false;
        for (int i = 0; i < cont_produto; i++) {
            if (produtoVencido(produto[i].validade)) {
                printf("Código: %d\nNome: %s\nValor: %.2f\nValidade: %s\nQuantidade: %d\n\n", produto[i].codigo, produto[i].nome, produto[i].valor, produto[i].validade, produto[i].quantidade);
                encontrado = true;
            }
        }
        if (!encontrado) {
            printf("Nenhum produto vencido encontrado\n\n");
        }
        break;
    }*/
    case 6:{
        consultarTotalVendas(*total_vendas);
        break;
    }
    
    default:
        break;
    }
}


void consultarTotalVendas(float totalVendas) {
    printf("Total de vendas: %.2f\n\n", totalVendas);
}



//Escolha 3
void consultarPessoa(Cliente usuario[], int cont_cliente){
     printf("Caso queira consultar por:\n1. CPF\n2. Nome\n3. Data de Nascimento\n\n");
    int tipo_consulta;
    scanf("%d", &tipo_consulta);

    switch (tipo_consulta) {
    case 1: 
    { 
        int cpf;
        printf("Digite o CPF: ");
        scanf("%d", &cpf);
        bool encontrado = false;
        for (int i = 0; i < cont_cliente; i++) {
            if (usuario[i].cpf == cpf) {
                printf("Cliente encontrado:\nCPF: %d\nNome: %s\nEndereço: %s\nTelefone: %d\nData de Nascimento: %s\n\n",usuario[i].cpf, usuario[i].nome, usuario[i].endereco, usuario[i].tel, usuario[i].nascimento);
                encontrado = true;
            }
        }
        if (!encontrado) {
            printf("Cliente não encontrado\n\n");
        }
        break;
    }
    case 2: 
    { 
        char nome[20];
        printf("Digite o nome: ");
        scanf(" %s", nome);
        bool encontrado = false;
        for (int i = 0; i < cont_cliente; i++) {
            if (strcmp(usuario[i].nome, nome) == 0) {
                printf("Cliente encontrado:\nCPF: %d\nNome: %s\nEndereço: %s\nTelefone: %d\nData de Nascimento: %s\n\n",usuario[i].cpf, usuario[i].nome, usuario[i].endereco, usuario[i].tel, usuario[i].nascimento);
                encontrado = true;
            }
        }
        if (!encontrado) {
            printf("Cliente não encontrado\n\n");
        }
        break;
    }
    case 3: 
    { 
        char nascimento[11];
        printf("Digite a data de nascimento (DD/MM/AAAA): ");
        scanf(" %s", nascimento);
        bool encontrado = false;
        for (int i = 0; i < cont_cliente; i++) {
            if (strcmp(usuario[i].nascimento, nascimento) == 0) {
                printf("Cliente encontrado:\nCPF: %d\nNome: %s\nEndereço: %s\nTelefone: %d\nData de Nascimento: %s\n\n",
                       usuario[i].cpf, usuario[i].nome, usuario[i].endereco, usuario[i].tel, usuario[i].nascimento);
                encontrado = true;
            }
        }
        if (!encontrado) {
            printf("Cliente não encontrado\n\n");
        }
        break;
    }
    default:
        printf("Opção inválida.\n\n");
        break;
    }
}




//Escolha 4
void realizarVenda(Item produto[], int *cont_produto, float *total_venda) {
    int codigo, qtd, produtoIndex;
    int formaPagamento;
    float valorFinal;
    float totalCompra = 0.0;

    printf("Digite o numero de produtos que deseja comprar: ");
    int numProdutos;
    scanf("%d", &numProdutos);

    for (int i = 0; i < numProdutos; i++) {
        printf("\nDigite o codigo do produto %d: ", i + 1);
        scanf("%d", &codigo);

        // Verifica se o produto está cadastrado
        produtoIndex = -1;
        for (int j = 0; j < *cont_produto; j++) {
            if (produto[j].codigo == codigo) {
                produtoIndex = j;
                break;
            }
        }

        if (produtoIndex == -1) {
            printf("\nProduto com codigo %d nao encontrado.\n", codigo);
            //continue;
        }

        printf("Digite a quantidade: ");
        scanf("%d", &qtd);

        
        if (qtd > produto[produtoIndex].quantidade) {
            printf("\nQuantidade solicitada excede o estoque disponivel. Estoque disponivel: %d\n", produto[produtoIndex].quantidade);
            //continue; 
        }

        
        

        totalCompra += produto[produtoIndex].valor * qtd;

        
    }

    printf("\nTotal da compra: %.2f\n", totalCompra);

    
    printf("Escolha a forma de pagamento:\n");
    printf("1. A vista (10%% de desconto)\n");
    printf("2. Parcelamento em 3x (sem juros)\n");
    printf("3. Parcelamento em 4x a 6x (10%% de juros)\n");
    scanf("%d", &formaPagamento);


    switch (formaPagamento) {
        case 1: 
            valorFinal = totalCompra * 0.9; 
            printf("Valor a ser pago à vista: %.2f\n", valorFinal);
            break;
        case 2: 
            valorFinal = totalCompra;
            printf("Valor de cada parcela em 3x: %.2f\n", valorFinal / 3);
            break;
        case 3: 
            valorFinal = totalCompra * 1.1; 
            printf("Valor total com juros: %.2f\n", valorFinal);
            printf("Valor de cada parcela:\n");
            for (int i = 4; i <= 6; i++) {
                printf("%d parcelas: %.2f\n", i, valorFinal / i);
            }
            break;
        default:
            printf("\nForma de pagamento invalida.\n");
            return; 
    }

    //troco
    float pagamento;
    printf("Digite o valor que o cliente esta pagando: ");
    scanf("%f", &pagamento);

    if (pagamento >= valorFinal) {
        printf("\nTroco: %.2f\n\n", pagamento - valorFinal);
        baixaEstoque(produto, codigo, qtd);
        *total_venda += valorFinal;
        
    } else {
        printf("\nValor insuficiente para completar a compra.\n");
    }


}


//escolha 5
void baixaEstoque(Item produto[], int codigo, int quantidade){
    int achou = 0;
    for (int i = 0; i < MAX; i++) {
        if (produto[i].codigo == codigo) {
            if(produto[i].quantidade >= quantidade){
                produto[i].quantidade -= quantidade;
                printf("\nEstoque atualizado: Produto %s, nova quantidade: %d\n", produto[i].nome, produto[i].quantidade);
            }else{
                printf("\nQuantidade superior ao estoque\n");
            }
            achou = 1;
        }
    }
    
    if(achou == 0){
        printf("\nProduto nao encontrado\n");
    }
}

