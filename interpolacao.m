close all;

% Definição do sinal original
f = 5;
Fs = 80;         % Taxa de amostragem original (Hz)
t = 0:1/Fs:1/f;    
y = sin(2*pi*f*t); % Sinal senoidal 

L = 4; % Fator de interpolação

% Inserção de zeros
x_zeros = zeros(1, L*length(y)); 
x_zeros(1:L:end) = y;            

t_interp = linspace(min(t), max(t), length(x_zeros));

% Design do filtro passa-baixa FIR (Janela de Hamming)
%Fc = Fs / 2;  % Frequência de corte (Nyquist do sinal original)
%N = 50;       % Ordem do filtro
%h = fir1(N, (Fc/(Fs*L/2)), 'low', hamming(N+1)); 

% Aplicação do filtro ao sinal interpolado
%x_interp = filter(h, 1, x_zeros);

figure;

subplot(2,1,1);
plot(t, y, 'b', 'LineWidth', 1.5, 'DisplayName', 'Sinal Original'); hold on;
stem(t, y, 'r', 'filled', 'DisplayName', 'Sinal Amostrado');
legend;
%title('Sinal Original');
xlabel('Tempo (s)');
ylabel('Amplitude');
grid on;

subplot(2,1,2);
stem(t_interp, x_zeros, 'r', 'filled'); hold on;
%plot(t_interp, x_zeros, 'b', 'LineWidth', 1);
title(['Sinal com Zeros Inseridos (Fator ', num2str(L), ')']);
xlabel('Tempo (s)');
ylabel('Amplitude');
grid on;

saveas(gcf, 'interpolacao.png');
%subplot(3,1,3);
%plot(t_interp, x_interp, 'b', 'LineWidth', 1.5); hold on;
%stem(t_interp, x_interp, 'g', 'filled');
%title('Sinal Interpolado após Filtro Passa-Baixa');
%xlabel('Tempo (s)');
%ylabel('Amplitude');
%grid on;
