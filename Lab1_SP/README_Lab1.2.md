Необходимо написать программу, позволяющую выполнять перекодировку текста из ASCII в Юникод и обратно. В качестве входных данных выступает файл с текстом. Программа при запуске получает параметр командной строки определяющий исходную кодировку файла (-a – ANSI файл, -u – Юникод файл).
____
Results
____
Outputs with next args:
- -a right_paths
```
C:\Users\Olena>F:\Desktop\SP_course\Lab1_SP\Lab1.2_SP\Debug\Lab1.2_SP.exe -a F:\Desktop\SP_course\Lab1_SP\Lab1.2_SP\from_ascii.txt F:\Desktop\SP_course\Lab1_SP\Lab1.2_SP\result_to_uni1.txt
<br>Tonight, you look under your bed, and lo and behold,
you find a monster! And you're immediately eaten.
Now, if you hadn't looked for the monster,
you wouldn't have found it and you'd still be happy in your bed,
instead of being slowly digested in the stomach sac of the creature.
But, with any luck, your sister or your brothers might have heard your screams,
and your endeavor will serve as a valuable lesson to them.
```
- -u right_paths
```
C:\Users\Olena>F:\Desktop\SP_course\Lab1_SP\Lab1.2_SP\Debug\Lab1.2_SP.exe -u F:\Desktop\SP_course\Lab1_SP\Lab1.2_SP\from_uni.txt F:\Desktop\SP_course\Lab1_SP\Lab1.2_SP\result_to_ascii.txt
Научный прогресс, задача которого расширять границы наших познаний о мире, на самом деле уничтожает его.
Научно-технический прогресс не просто грозит катастрофой. Катастрофа уже началась. Каким будет апокалипсис?
Ответом является термин общеизвестный, но не вообразимый без детального описания в данном документе. Это война.
Мы считаем, что уже поняли реальность. Но на самом деле наш мир - один из многих.
Мало кто знает, что способ перемещения между ними открыт более развитыми представителями.
Отрицательный эффект подобных перемещений окажется необратимым как для их мира, так и для нашего.
Все начнется с серии казалось бы незаметных на первый взгляд аномалий, число которых будет расти как раковая опухоль,
пока не станет очевидным один факт: выжить сможет лишь один мир. Либо мы, либо они.
Грядет война, война не из ненависти и злости, а битва за выживание.
Среди нас много воинов грядущего противостояния.

- Правительство поручило тебе изобрести способ управления разумом?
- Нет, не правительство. Меня наняло рекламное агентство.

- Какая главная мечта всего человечества?
- Мир во всем мире?
- Нет, вряд ?ээээ[cЄ.B?и. Это социальная установка навязанная осознанием того, что все мы смертны.
- Надо было сказать <больше вкуса, меньше калорий>.

- Искусство шахмат - понять, когда фигура представляет ценность,
и в этот момент быть готовым ею пожертвовать. Так как пустота,
ощущение, что ты потерял самое ценное, дает массу возможностей.
Влияние усиливается, а желания становятся судьбоносными.
Например, в этой партии самая ценная фигура - слон.
Поэтому, чтобы выиграть партию, надо пожертвовать слоном.

- Зачем?
- О, Боже правый! Сегодня день глупых вопросов, а мне об этом никто не сообщил!

- Я не понимаю, как убийство миллиардов людей вообще может быть ради общего блага.
- Это потому, что у тебя ещё есть такая роскошь как принципы! Я вынужден быть прагматичным.
```
- -u wrong_paths
```
C:\Users\Olena>F:\Desktop\SP_course\Lab1_SP\Lab1.2_SP\Debug\Lab1.2_SP.exe -u F:\Desktop\SP_course\Lab1_SP\Lab1.2_SP\from_uni.txt F:\Desktop\SP_course\Lab1_SP\Lab1.2_SP\result_to_ascii.txt

Something went wrong(
ERROR was generated: failed with 0x50 code
ERROR formatted message: Файл существует.
```
- without required args
```
C:\Users\Olena>F:\Desktop\SP_course\Lab1_SP\Lab1.2_SP\Debug\Lab1.2_SP.exe -upset

You made a mistake !!!
Only 4 arguments available:
-a => ASCII to UNICODE
-u => UNICODE to ASCII
file 1 => full path to source
file 2 => full path to result
```


