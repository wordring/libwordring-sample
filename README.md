libwordring-sample
====

libwordring を使うサンプル集です。

## libwordring をサブモジュールとして CMake で使う

- サブモジュールとして追加した **libwordring** フォルダを **add_subdirectory()** します
- **libwordring/include** フォルダを **include_directories()** します
- **wordring** を **target_link_libraries** します

以上です。

サンプルの **CMakeLists.txt** を見てください。

## サンプル・プロジェクトの御案内

| プロジェクト | 御説明 |
|----|----|
| html/crawl | HTML ページから URL を抜き出す |
|  |  |