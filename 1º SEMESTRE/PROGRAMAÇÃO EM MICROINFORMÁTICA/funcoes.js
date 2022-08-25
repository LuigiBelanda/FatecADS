var op = 10;

switch (op) {
    case 1:
        console.log("O número é", exercicio1(0));
    break;
    case 2:
        console.log("Escreva um programa que leia um número e exiba o seu módulo. \n");
        console.log("O módulo é", exercicio2(-1));
    break;
    case 3:
        console.log("O número é", exercicio3(3));
    break;
    case 4:
        console.log("O maior valor é:", exercicio4(5,16,3));
    break;
    case 5:
        console.log(exercicio5(3));
    break;
    case 6:
        console.log("Escreva um programa que leia 3 valores e escreva a soma dos 2 maiores\n");
        console.log("A soma dos 2 maiores números é: ", exercicio6(1,2,3));
    break;
    case 7:
        console.log("Escreva um programa que leia 3 números e calcule a média ponderada entre eles. Considere que o maior número recebe peso 5 e os outros dois recebem peso 2,5");
        console.log ("Média ponderada:", exercicio7(1,2,3) );
    break;
    case 8:
        console.log("O novo salário é:", exercicio8(1500));
        break;
    case 9:
        console.log ("O valor a pagar com desconto é:", exercicio9(40, 'a'));  
    case 10:
        console.log (exercicio10(4000, 39000, 12));
    default:

        break;
}


function exercicio1 (valor){
    if (valor > 0)  return "Positivo"
    else if (valor = 0) return "nem positivo e nem negativo"
    else return "Negativo"
}
function exercicio2(valor) {
    if (valor <0) return (-valor);
    else return valor;
}
function exercicio3(valor){
    if (( valor % 2 )==0) return "par";
    else return "ímpar";
}
function exercicio4(valor1, valor2, valor3) {
    if (valor1 > valor2 && valor1 > valor3) return valor1;
    else if (valor2 > valor3) return valor2;
    else return valor3;
}
function exercicio5 (num){
   
    let mes = ["null", "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", 
      "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"];
    
      if (num < 1 || num > 12)
          console.log("Digite um número de 1 a 12");
      else {
        switch (num) {      
        case (1 || 3 || 5 || 7 || 8 || 10 || 12):
            console.log("O mês de", mes[num],"tem 31 dias");
            break;
        case (2):
            console.log("O mês de " + mes[num] + "tem 28 dias ou 29 nos anos bissestos");
            break;
        default:
            console.log("O mês de " + mes[num] + " tem 30 dias");
            break;
        }
    }
}
function exercicio6 (num1, num2, num3) {
let soma = 0;  
if (num1 > num2 || num1 > num3){
    soma += num1;
}
if (num2 > num1 || num2 > num3)
    soma += num2;

if (num3 > num1 || num3 > num2)
    soma += num3;
return soma;
}
function exercicio7 (num1, num2, num3){
let media = 0;  
if (num1 > num2 &&  num1 > num3)
    media = (((num1 * 5) + (num2 * 2.5)+ (num3 * 2.5))/10);
else if (num2 > num3)
    media = (((num2 * 5)+ (num1 * 2.5)+ (num3 * 2.5))/10)
else 
    media = (((num3*5)+(num2*2.5)+(num1*2.5))/10);
}
function exercicio8 (salario){
    if ((salario * 0,11)> 334,29){
        return (salario - 334,29);
    }else
    return (salario * 0,89);
}
function exercicio9(litragem, combustivel) {
    let vgas = 2.70, valool = 1.90;
    if (litragem < 25){
        if (combustivel=='g'){
            return (litragem * (vgas * 0.97));
        }else if (combustivel == 'a'){
            return (litragem * (valool * 0.98));
        }
    }else {
        if (combustivel=='g'){
            return (litragem * (vgas * 0.95));
        }else if (combustivel =='a'){
            return (litragem * (valool * 0.96));
        }
    }
}
function exercicio10 (salario, vpretendido, prestacoes){
    //console.log("Salario:", salario, "Valor Pretendido:", vpretendido, "prestações:", prestacoes);
    //console.log("Valor máximo empréstimo:", (salario*10),"\nValor máximo da prestação", (salario * 0.3));
    
    if (vpretendido > (salario * 10))
        console.log("Valor ultrapassa o limite de:", (salario*10));
    else if ((vpretendido/prestacoes)> (salario*0.3))
        console.log("Valor ultrapassa a renda mensal. \nValor máximo da prestação:", (salario*0.3), "\nValor máximo do empréstimo", (salario*10),"\n\nValor da prestação atual:", (vpretendido/prestacoes));
    else
        console.log("Empréstimo pode ser concedido. valor da prestação:",prestacoes, "de", (vpretendido / prestacoes));
}   
