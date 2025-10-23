#日本語訳

C++98（C++20でも同様）にはインターフェースは存在しません。
しかし、純粋抽象クラスは一般的にインターフェースと呼ばれます。
そこで、この最後の演習では、このモジュールの理解を深めるために、インターフェースを実装してみましょう。

以下のAMateriaクラスの定義を完成させ、必要なメンバー関数を実装してください。

class AMateria
{
protected:
[...]
public:
AMateria(std::string const & type);
[...]
std::string const & getType() const; //マテリアの型を返します
virtual AMateria* clone() const = 0;
virtual void use(ICharacter& target);
};

マテリア「Ice」と「Cure」の具象クラスを実装してください。
型を設定するには、クラス名を小文字で記述してください（Iceの場合は「ice」、Cureの場合は「cure」）。
もちろん、これらのメンバー関数 clone() は同じ型の新しいインスタンスを返します
（つまり、アイスマテリアを複製すると、新しいアイスマテリアが生成されます）。

use(ICharacter&) メンバー関数は以下を表示します。
• Ice: "* は <name> にアイスボルトを発射します *"
• Cure: "* は <name> の傷を治します *"

<name> は、パラメータとして渡されるキャラクターの名前です。山括弧 (< と >) は出力しないでください。

ヒント:: マテリアを別のマテリアに割り当てる際に、型をコピーするのは意味がありません。

以下のインターフェースを実装する具象クラス Character を作成してください。

class ICharacter
{
public:
virtual ~ICharacter() {}
virtual std::string const & getName() const = 0;
virtual void equip(AMateria* m) = 0;
virtual void unequip(int idx) = 0;
virtual void use(int idx, ICharacter& target) = 0;
};

キャラクターは4つのインベントリスロットを持ち、マテリアは最大4つまで装備できます。

作成時はインベントリは空です。キャラクターは、スロット0からスロット3の順番で、最初に見つかった空きスロットにマテリアを装備します。
インベントリがいっぱいの状態でマテリアを追加しようとしたり、存在しないマテリアを使用/装備解除しようとしても、何も起こりません
（ただし、バグは発生させないでください）。

unequip() メンバー関数はマテリアを削除してはいけません！

ヒント: キャラクターが床に残したマテリアは、自由に処理してください。unequip() などの呼び出しの前にアドレスを保存してください。
ただし、メモリリークを回避する必要があることを忘れないでください。

use(int, ICharacter&) メンバー関数は、スロット[idx]のマテリアを使用し、targetパラメータを AMateria::use 関数に渡す必要があります。

注意::キャラクターのインベントリは、あらゆる種類のマテリアに対応します。

キャラクターには、キャラクター名をパラメータとして受け取るコンストラクタが必要です。
キャラクターのコピー（コピーコンストラクタまたはコピー代入演算子を使用）は、階層構造を持つ必要があります。
コピー中は、新しいマテリアがインベントリに追加される前に、既存のマテリアを削除する必要があります。
もちろん、キャラクターが破棄された場合には、既存のマテリアも削除する必要があります。
以下のインターフェースを実装する具象クラス MateriaSource を記述してください。

class IMateriaSource
{
public:
virtual ~IMateriaSource() {}
virtual void learnMateria(AMateria*) = 0;
virtual AMateria* createMateria(std::string const & type) = 0;
};

• learnMateria(AMateria*)
パラメータとして渡されたマテリアをコピーし、メモリに保存します。これにより、後で複製できるようになります。
キャラクターと同様に、マテリアソースは最大4つのマテリアを認識できます。マテリアは必ずしも一意である必要はありません。

• createMateria(std::string const &)
新しいマテリアを返します。これは、マテリアソースが以前に学習したマテリアのコピーで、パラメータで渡された型と同じ型を持ちます。
型が不明な場合は0を返します。

簡単に言うと、マテリアソースは必要に応じてマテリアを生成するために、マテリアの「テンプレート」を学習できる必要があります。
そうすれば、型を識別する文字列だけで新しいマテリアを生成できるようになります。

このコードを実行します。
int main()
{
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
delete bob;
delete me;
delete src;
return 0;
}

$> clang++ -W -Wall -Werror *.cpp
$> ./a.out | cat -e
* shoots an ice bolt at bob *$
* heals bob's wounds *$

いつものように、上記よりも多くのテストを実装して提出してください。
演習03を行わなくても、このモジュールは合格できます。