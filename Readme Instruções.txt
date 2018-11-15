Para adiconar cartões extra ao leitor basta ligar se ao arduino com cabo usb e desligalo da fonte de alimentação
De seguida passar o cartao no leitor e no monitor de série vai aparecer codigo do cartão que vai ser utilizado
Se for para autorizar um cartão basta copiar o if abaixo e trocar os * pelo codigo do monitor de serial e colocar
no programa junto dos outros.

if (uid[3] == **)        //identificação do cartão
  {tone(8,2000,200);
  digitalWrite(10,HIGH);//LED verde
  digitalWrite(12,HIGH);//abre porta
  delay(2000);
  digitalWrite(10,LOW);//LED verde
  digitalWrite(12,LOW);//fecha porta
  }


Se for para bloquear um cartão basta repetir o mesmo processo mas para o if abaixo trocando os * pelo codigo do monitor de série


 if (uid[3] == **)     //identificação do cartão
  {tone(8,400,200);
  delay(200);
  tone(8,600,200);
  digitalWrite(6,HIGH);//LED vermelho
  delay(2000);
  digitalWrite(6,LOW);//LED vermelho
  }