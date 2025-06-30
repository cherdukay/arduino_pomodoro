# Pomodoro Zamanlayıcı (Arduino ile Fiziksel Uygulama)

Bu proje, **Ankara Üniversitesi Eğitim Bilimleri Fakültesi** Bilgisayar ve Öğretim Teknolojileri Öğretmenliği Bölümü'nde verilen **BÖZ214 Fiziksel Programlama** dersi kapsamında gerçekleştirilmiştir.

##  Proje Amacı

Bu çalışmanın amacı, Pomodoro tekniğini fiziksel bir zamanlayıcı cihazla uygulamak ve zaman yönetimini dijital ekran bağımlılığı olmadan desteklemektir. Arduino tabanlı geliştirilen bu cihaz, 25 dakika çalışma ve 5 dakika mola döngüsünü otomatik olarak sürdüren; kullanıcıya sesli ve görsel bildirimler sunan taşınabilir bir sistemdir.

## Kullanılan Bileşenler

- Arduino UNO R3
- 16x2 LCD ekran
- 3 adet push-button (menü kontrolü için)
- 10K ohm potansiyometre (LCD kontrast ayarı)
- Buzzer
- 220 ohm direnç
- Breadboard ve jumper kablolar

##  Özellikler

- Otomatik mod: 25 dk çalışma + 5 dk mola (klasik Pomodoro döngüsü)
- Özel süreli mod: Kullanıcının belirleyeceği toplam süre boyunca ardışık döngüler
- LCD ekran üzerinden zaman ve mod görüntüleme
- Buzzer ile sesli uyarılar
- Butonlarla menü gezintisi ve mod seçimi
- Powerbank ile taşınabilir çalışma desteği

##  Geliştirme Ortamı

- Arduino IDE
- LiquidCrystal kütüphanesi (LCD kontrolü için)
- C++ tabanlı Arduino dili

##  Dosyalar

- `pomodoro.ino` – Arduino kaynak kodu
- `readme.md` – Bu açıklama dosyası
