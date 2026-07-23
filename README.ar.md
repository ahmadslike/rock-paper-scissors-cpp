[English](README.md) | **العربية**

<div dir="rtl">

# لعبة حجرة ورقة مقص — C++ Console Game 🪨📄✂️

لعبة حجرة ورقة مقص على الـ Console بتلعب فيها ضد الكمبيوتر، مبنية بلغة ++C على مبدأ **"فرّق تسد" (Divide & Conquer)**
> المشروع الأول من كورس **Algorithms & Problem-Solving Level 2** (الكورس الخامس من خارطة الطريق للدكتور محمد أبو هدهود).

## المميزات

- العب من 1 إلى 10 جولات ضد الكمبيوتر (مع validation كامل للمدخلات)
- نتيجة كل جولة بألوان واضحة (أخضر = فزت، أحمر = فاز الكمبيوتر، أصفر = تعادل)
- صوت تنبيه عندما يفوز الكمبيوتر بالجولة (Linux)
- لوحة نتائج نهائية: عدد مرات الفوز والخسارة والتعادل والفائز الإجمالي
- إمكانية اللعب من جديد بدون إعادة تشغيل البرنامج

## مثال على اللعب

</div>

```
How many rounds do you want [1 to 10]? 3

____________ Round[1] ____________
Your Choice [1]: Stone, [2]: Paper, [3]: Scissors ? 2
Player1 Choice : Paper
Computer Choice : Stone
Round Winner : [ Player1 ]

...

____________ [ Game Results ] ____________
Game Round : 3
Player1 won times : 2
Computer won times : 1
Draw times : 0
Final Winner : [ Player1 ]

Do you want to play again y/n ?
```

<div dir="rtl">

## بنية الكود — فرّق تسد

كل Function مركزة على مسؤولية واحدة:

| الـ Function | المسؤولية |
|---|---|
| `ReadNumberOfRound()` | قراءة عدد الجولات والتحقق منه (1–10) |
| `UserChoice()` | قراءة اختيار اللاعب والتحقق منه |
| `RandomNumber(From, To)` | توليد رقم عشوائي ضمن مدى محدد |
| `ComputerChoice()` | اختيار حركة الكمبيوتر |
| `PlayRound()` | لعب جولة كاملة وتحديث النقاط |
| `GetChoiceName()` | تحويل الاختيار من enum إلى نص مقروء |
| `PlayGameRounds()` | تشغيل كل الجولات وعرض نتيجة كل جولة |
| `PrintFinalResults()` | طباعة النتائج النهائية والفائز الإجمالي |
| `StartGame()` | حلقة اللعبة الكاملة مع خيار اللعب من جديد |

حالة اللعبة (النقاط وآخر الاختيارات) محفوظة في `struct` واحد يُمرَّر بالـ reference — بدون أي global variables.

## التشغيل

</div>

```bash
g++ main.cpp -o rps
./rps
```

<div dir="rtl">

> **ملاحظة:** مسح الشاشة وصوت التنبيه يستخدمان أوامر Linux (`clear` و`speaker-test`). على Windows، استبدل `system("clear")` بـ `system("cls")` واحذف سطر الصوت — أو استخدم `#ifdef _WIN32`.

## شو تدربت عليه

- تقسيم البرنامج إلى Functions كل واحدة بمسؤولية واحدة (فرّق تسد)
- استخدام `enum` مع `struct` لتمثيل حالة اللعبة بشكل نظيف
- تمرير الحالة بالـ reference بدل الـ global variables
- الـ validation للمدخلات باستخدام حلقات `do...while`
- استخدام ANSI escape codes للألوان في المخرجات مع صوت تنبيه

## المؤلف

**أحمد سليق** — مطوّر يتعلم ذاتياً ويبني بشكل علني (Build in Public).

- LinkedIn: [linkedin.com/in/ahmad-slik-99661840b](https://www.linkedin.com/in/ahmad-slik-99661840b)
- Portfolio: [ahmadslik.netlify.app](https://ahmadslik.netlify.app)
- GitHub: [github.com/AhmadSlik](https://github.com/AhmadSlik)

</div>
