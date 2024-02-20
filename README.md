# MCU_course_prh

Разработать контроллер, реализующий следующие функции: 
• Многоканальное измерение амплитуды в диапазоне (0-5)В, количество каналов -8, погрешность измерения -0,05%. 
• Источники измерительного сигнала запускаются одновременно по команде ОМК.  
• По каждому каналу определить средне-арифметическое из 16 измерений  
• Порядок опроса каналов  и номер выводимого на индикацию канала задается с клавиатуры и контролируется 7-сегментным  индикатором  
• В момент окончания работы включить красный светодиод и данные передать по интерфейсу RS-232 на скорости 1200б/с, если пришел внешний запрос прерываний.