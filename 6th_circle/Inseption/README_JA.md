*This project has been created as part of the 42 curriculum by mkuida.*

# Inception

## 🐍 Description
このプロジェクトの目的は、Dockerを使用して複数のDockerコンテナからなるシステム管理インフラを構築することです。
①Nginx（TLSのみ）、②MariaDB、③WordPressの３つをそれぞれ専用のコンテナで動作させ、適切にネットワークを分離した安全なウェブサーバー環境を構築します。
最終的にはブラウザを用いて以下にアクセスできるようになれば目標達成です。
mandatory -> https://${USER}.42.fr
bonus     ->https://${USER}.42.fr/static

## 🛠 Instructions
### ビルドと実行
1. **リポジトリをクローン**:
   `git clone <repository_url>`
2. **設定**:
   `secrets` ディレクトリ内に４つの `.txt` ファイルを作成し、タイトルのパスワードを設定します。

> **補足:** クローン時に存在する.txt.exampleから.exampleを削除して中身を記述すれば良い形に準備されています。<br>
> 中に記述すすパスワードは公開しないでください。以下の方法、またはそれ相当の強度のパスワード作成をおすすめします。 <br>
> `pwgen 16 1`


3. **起動**:
   `make`
   このコマンドにより、必要なボリュームディレクトリの作成、Dockerfileからのイメージビルド、コンテナの起動が自動で行われます。

   `make bonus`
   このコマンドにより、上記に加え、静的htmlファイルへのアクセスも可能になります。

## 📖 概念の比較 (Concepts Comparison)

### 1. Virtual Machines vs Docker
| 比較項目 | Virtual Machines (VM) | Docker (Container) |
| :--- | :--- | :--- |
| **仮想化の対象** | ハードウェア・OS全体 | プロセス・アプリケーション |
| **カーネル** | 独自のカーネルを持つ | ホストOSのカーネルを共有 |
| **リソース消費** | 重い (数GB〜) | 非常に軽量 (数MB〜) |
| **起動時間** | 数分 (OSの起動が必要) | 数秒 |



### 2. Secrets vs Environment Variables
* **Environment Variables (`.env`)**:
    * 設定が容易で一般的。
    * `docker inspect` 等で値が露出する可能性があるため、取り扱いに注意が必要。
    * 本プロジェクトでは公開情報のみを記載しているため、隠していない。
* **Docker Secrets**:
    * メモリ上にのみ一時的にマウントされ、ディスクに書き込まれないため非常に安全。
    * 本プロジェクトでは `.env` と連携させつつ、機密性を保つ設計としています。

### 3. Docker Network vs Host Network
* **Docker Network (Bridge)**:
    * コンテナ間を独立したサブネットで接続。
    * 不要な通信を遮断でき、必要なポートのみ公開するため**セキュリティ上推奨**。
* **Host Network**:
    * コンテナがホストのネットワークをそのまま使用。
    * 分離されないため、ポートの競合やセキュリティリスクがある。

### 4. Docker Volumes vs Bind Mounts
* **Docker Volumes**:
    * Dockerエンジンが管理する専用領域。
    * ホストのファイルシステム構造に依存せず、パフォーマンスや管理性に優れる。
* **Bind Mounts**:
    * ホスト上の特定のディレクトリを直接指定してマウントする。

---

## 📚 Resources
- [Docker Documentation](https://docs.docker.com/)
- [Nginx Official Site](https://nginx.org/)
- [WordPress CLI Guide](https://developer.wordpress.org/cli/commands/)

---

## 🤖 AI Use Disclosure
本プロジェクトの開発にあたり、AI（Google Gemini）を以下のタスクに使用しました：
* プロジェクトドキュメント（README, USER_DOC, DEV_DOC）の構成案作成、翻訳作業、デコレーション
* Makefileの構造定義およびエラーハンドリングのアドバイス。
* ネットワークトラブルシューティング（SSH接続やポートフォワーディング）の補助。
* 専門用語の概念比較（Docker vs VM 等）の整理。
* 本当にありがとう、いつか有料版にしたい