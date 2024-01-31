#ifndef _QUERY1_OUTPUT_
#define _QUERY1_OUTPUT_

/**
 * @file query1_output.h
 * @brief Documentação relacionada ao output da Query 1.
 */

/**
 * @brief Converte e guarda os resultados da Query 1 em um ficheiro de texto.
 *
 * Esta função converte e guarda os resultados da Query 1 em um ficheiro de texto,
 * conforme especificado pelos parâmetros.
 *
 * @param[in] i Identifica o número do ficheiro.
 * @param[in] linha A linha de texto a ser guarda no ficheiro.
 */
void to_txt_0(int i, const char *linha);

/**
 * @brief Converte e guarda os resultados da Query 1 para utilizadors em um ficheiro de texto.
 *
 * Esta função converte e guarda os resultados da Query 1 para utilizadors em um ficheiro de texto,
 * conforme especificado pelos parâmetros.
 *
 * @param[in] i Identifica o número do ficheiro.
 * @param[in] name O nome do utilizador.
 * @param[in] sex O sexo do utilizador.
 * @param[in] idade A idade do utilizador.
 * @param[in] country O país do utilizador.
 * @param[in] passport O passaporte do utilizador.
 * @param[in] nf O número de voos do utilizador.
 * @param[in] nr O número de reservas do utilizador.
 * @param[in] t O total gasto pelo utilizador.
 */
void to_txt_1_u(int i, char *name, char *sex, int idade, char *country, char *passport, int nf, int nr, double t);

/**
 * @brief Converte e guarda os resultados da Query 1 para voos em um ficheiro de texto.
 *
 * Esta função converte e guarda os resultados da Query 1 para voos em um ficheiro de texto,
 * conforme especificado pelos parâmetros.
 *
 * @param[in] i Identifica o número do ficheiro.
 * @param[in] airline A companhia aérea do voo.
 * @param[in] plane O modelo da aeronave do voo.
 * @param[in] origem A cidade de origem do voo.
 * @param[in] destino A cidade de destino do voo.
 * @param[in] sdd A data e hora de partida do voo.
 * @param[in] sad A data e hora de chegada do voo.
 * @param[in] p O preço do voo.
 * @param[in] delay O tempo de atraso do voo.
 */
void to_txt_1_f(int i, char *airline, char *plane, char *origem, char *destino, char *sdd, char *sad, int p, char *delay);

/**
 * @brief Converte e guarda os resultados da Query 1 para reservas de hotéis em um ficheiro de texto.
 *
 * Esta função converte e guarda os resultados da Query 1 para reservas de hotéis em um ficheiro de texto,
 * conforme especificado pelos parâmetros.
 *
 * @param[in] i Identifica o número do ficheiro.
 * @param[in] hotel_i O identificador do hotel.
 * @param[in] hotel_n O nome do hotel.
 * @param[in] stars O número de estrelas do hotel.
 * @param[in] bd A data de início da reserva.
 * @param[in] ed A data de término da reserva.
 * @param[in] ib O tipo de quarto reservado.
 * @param[in] n O número de quartos reservados.
 * @param[in] t O total gasto na reserva do hotel.
 */
void to_txt_1_r(int i, char *hotel_i, char *hotel_n, char *stars, char *bd, char *ed, char *ib, int n, double t);

#endif /* _QUERY1_OUTPUT_ */
