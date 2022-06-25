/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:25:35 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/06/25 19:00:18 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Você deve usar o miniLibX. A versão que está disponível no sistema operacional ou de suas fontes. Se você optar por trabalhar com as fontes, precisará aplicar as mesmas regras para sua libft como aquelas escritas acima na parte de Instruções Comuns.

// A gestão da sua janela deve permanecer suave: mudar para outra janela, minimizar, etc.

// Exiba diferentes texturas de parede (a escolha é sua) que variam dependendo de qual lado a parede está voltada (Norte, Sul, Leste, Oeste).

// Seu programa deve ser capaz de definir as cores do piso e do teto para duas cores diferentes.

// O programa exibe a imagem em uma janela e respeita as seguintes regras:
//         As teclas de seta esquerda e direita do teclado devem permitir que você
//          olhe para a esquerda e para a direita no labirinto.

//          As teclas W, A, S e D devem permitir que você mova o ponto de
//          vista através do labirinto.

//         Pressionar ESC deve fechar a janela e sair do programa
//         de forma limpa.

//        Clicar na cruz vermelha na moldura da janela deve fechar a
//        janela e saia do programa de forma limpa.

//      O uso de imagens do minilibX é fortemente recomendado.

// Seu programa deve ter como primeiro argumento um arquivo de descrição de cena com a extensão .cub.

// O mapa deve ser composto por apenas 6 caracteres possíveis: 0 para um espaço vazio, 1 para uma parede e N,S,E ou W para a posição inicial do jogador e orientação de desova. Este é um mapa válido simples:

// O mapa deve estar fechado/cercado por paredes, caso contrário o programa deve retornar um erro.

// Exceto pelo conteúdo do mapa, cada tipo de elemento pode ser separado por uma ou mais linhas vazias.

// Exceto pelo conteúdo do mapa que sempre deve ser o último, cada tipo de elemento pode ser definido em qualquer ordem no arquivo.

// Com exceção do mapa, cada tipo de informação de um elemento pode ser separado por um ou mais espaços.

// O mapa deve ser analisado como aparece no arquivo. Os espaços são uma parte válida do mapa e dependem de você. Você deve ser capaz de analisar qualquer tipo de mapa, desde que respeite as regras do mapa

#include "./include/cub3D.h"

int	key_event(int key, t_param *param)
{
	printf("%d\n", key);

	if (key == 53)
	{
		free(param->mlx_win);
		free(param->mlx);
		exit(0);
	}
}

int	main()
{
	t_param	*param;

	param = malloc(sizeof(t_param) * 1);
	param->mlx = mlx_init();
	param->mlx_win = mlx_new_window(param->mlx, 600, 600, "Cub3D");
	mlx_key_hook(param->mlx_win, &key_event, param);
	mlx_loop_hook(param->mlx, &key_event, &param);
	mlx_loop(param->mlx);
}
