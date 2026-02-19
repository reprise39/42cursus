*This project has been created as part of the 42 curriculum by mkuida.*

# Inception

## 🐍 Description
このプロジェクトの目的は、Dockerを使用して複数のDockerコンテナからなるシステム管理インフラを構築することです。
Nginx（TLSのみ）、MariaDB、WordPressをそれぞれ専用のコンテナで動作させ、適切にネットワークを分離した安全なウェブサーバー環境を構築します。

## 🛠 Instructions
### ビルドと実行
1. `srcs/.env` ファイルを作成し、環境変数を設定してください。
2. 以下のコマンドを実行します：
   ```bash
   make

Virtual Machines vs Docker
VM: カーネルを含めたOS全体を仮想化するため、リソース消費が重い。

Docker: ホストOSのカーネルを共有しプロセスを分離するため、軽量で起動が速い。

Secrets vs Environment Variables
Env: 設定が容易だが、docker inspect 等で値が露出する可能性がある。

Secrets: メモリ上にのみ保存され、ディスクに書き込まれないため安全（本プロジェクトでは .env を使用し、機密性を保つ）。

Docker Network vs Host Network
Docker Network: コンテナ間を独立したサブネットで接続し、不要な通信を遮断できる（セキュリティ上推奨）。

Host Network: コンテナがホストのネットワークをそのまま使うため分離されない。

Docker Volumes vs Bind Mounts
Docker Volumes: Dockerが管理する領域。OSに依存せず、パフォーマンスや管理性に優れる。

Bind Mounts: ホスト上の特定のディレクトリを直接指定してマウントする。

📚 Resources
Docker Documentation

Nginx Official Site

WordPress CLI Guide

AI Use Disclosure
本プロジェクトでは、AI（Google Gemini）を以下のタスクに使用しました：

プロジェクトのドキュメント（README, USER_DOC, DEV_DOC）の構成案作成。

Makefileの構造定義およびエラーハンドリングのアドバイス。

ネットワークトラブルシューティング（SSH接続やポートフォワーディング）の補助。

専門用語の概念比較（Docker vs VM 等）の整理。