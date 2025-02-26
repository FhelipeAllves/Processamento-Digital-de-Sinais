close all;

% PDS - Decimação de um sinal 

% Sinal de exemplo (100Hz amostrado a 3kHz)
f = 100
fs = 3000;
t = 0:1/fs:2*1/f;
sinal = sin(2 * pi * f * t);

% Decimação por fator M = 10
M = 3;
% filtro_fir = fir1(100, 1/M); % Filtro FIR para evitar aliasing
% sinal_passa_baixa = filter(filtro_fir, 1, sinal);
sinal_decimado = sinal(1:M:end);

% Novo eixo do tempo 
t_decimado = t(1:M:end);

% Plot dos sinais
figure;
plot(t, sinal, 'b*', 'DisplayName', 'Sinal Original', 'LineWidth', 1);
hold on;
plot(t_decimado, sinal_decimado, 'ro', 'DisplayName', 'Sinal Decimado', 'LineWidth', 3);
legend;
xlabel('Tempo (s)');
ylabel('Amplitude');
grid on;
hold off;

saveas(gcf, 'sinal_decimado.png'); 
