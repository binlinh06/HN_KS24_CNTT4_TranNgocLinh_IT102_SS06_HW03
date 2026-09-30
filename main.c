#include <stdio.h>
#include <string.h>

#define MAX 100
#define HAN_MUON 14
#define TIEN_PHAT_MOI_NGAY 5000

int main() {
    char maPhieu[MAX][20];
    char maSach[MAX][20];
    int soNgayMuon[MAX];

    int soLuong = 0;
    int luaChon;

    do {
        printf("\n");
        printf("====================================================================\n");
        printf("       HE THONG QUAN LY MUON TRA SACH (LOGISTICS)\n");
        printf("====================================================================\n");
        printf("1. Them moi phieu muon sach (Create)\n");
        printf("2. Hien thi danh sach phieu muon & Tien phat qua han (Read)\n");
        printf("3. Cap nhat so ngay muon sach (Update)\n");
        printf("4. Xac nhan tra sach / Xoa phieu muon (Delete)\n");
        printf("5. Thoat chuong trinh\n");
        printf("====================================================================\n");
        printf("Lua chon cua ban (1-5): ");

        scanf("%d", &luaChon);

        // Xoa ky tu '\n' con lai trong bo dem
        while (getchar() != '\n');

        switch (luaChon) {

            // =========================================================
            // 1. THEM MOI PHIEU MUON
            // =========================================================
            case 1: {
                if (soLuong >= MAX) {
                    printf("\nBo nho danh sach da day, khong the them moi!\n");
                    break;
                }

                printf("\n--- THEM MOI PHIEU MUON ---\n");

                char maNhap[20];
                int biTrung = 0;

                printf("Nhap ma phieu: ");
                scanf("%19s", maNhap);

                while (getchar() != '\n');

                // Kiem tra ma phieu da ton tai hay chua
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        biTrung = 1;
                        break;
                    }
                }

                if (biTrung == 1) {
                    printf("Ma phieu da ton tai trong he thong!\n");
                    break;
                }

                // Luu ma phieu
                strcpy(maPhieu[soLuong], maNhap);

                // Nhap ma sach
                printf("Nhap ma sach: ");
                scanf("%19s", maSach[soLuong]);

                while (getchar() != '\n');

                // Nhap so ngay muon
                do {
                    printf("Nhap so ngay muon: ");
                    scanf("%d", &soNgayMuon[soLuong]);

                    while (getchar() != '\n');

                    if (soNgayMuon[soLuong] <= 0) {
                        printf("Loi: So ngay muon phai lon hon 0!\n");
                    }

                } while (soNgayMuon[soLuong] <= 0);

                soLuong++;

                printf("Them moi phieu muon thanh cong!\n");

                break;
            }

            // =========================================================
            // 2. HIEN THI DANH SACH + TINH TIEN PHAT
            // =========================================================
            case 2: {
                if (soLuong == 0) {
                    printf("\nDanh sach phieu muon hien dang rong!\n");
                    break;
                }

                printf("\n");
                printf("=========================== DANH SACH PHIEU MUON ===========================\n");

                printf("%-5s %-12s %-15s %-15s %-18s %-18s\n",
                       "STT",
                       "Ma Phieu",
                       "Ma Sach",
                       "So Ngay Muon",
                       "Trang Thai",
                       "Tien Phat (VNĐ)");

                printf("----------------------------------------------------------------------------\n");

                int tongTienPhat = 0;

                for (int i = 0; i < soLuong; i++) {

                    int ngayQuaHan;
                    int tienPhat;

                    if (soNgayMuon[i] > HAN_MUON) {
                        ngayQuaHan = soNgayMuon[i] - HAN_MUON;
                        tienPhat = ngayQuaHan * TIEN_PHAT_MOI_NGAY;

                        printf("%-5d %-12s %-15s %-15d %-18s %-18d\n",
                               i + 1,
                               maPhieu[i],
                               maSach[i],
                               soNgayMuon[i],
                               "QUA HAN",
                               tienPhat);
                    } else {
                        tienPhat = 0;

                        printf("%-5d %-12s %-15s %-15d %-18s %-18d\n",
                               i + 1,
                               maPhieu[i],
                               maSach[i],
                               soNgayMuon[i],
                               "DUNG HAN",
                               tienPhat);
                    }

                    tongTienPhat += tienPhat;
                }

                printf("----------------------------------------------------------------------------\n");
                printf("Tong so phieu muon: %d\n", soLuong);
                printf("Tong tien phat: %d VNĐ\n", tongTienPhat);

                break;
            }

            // =========================================================
            // 3. CAP NHAT SO NGAY MUON
            // =========================================================
            case 3: {
                if (soLuong == 0) {
                    printf("\nDanh sach phieu muon hien dang rong!\n");
                    break;
                }

                char maNhap[20];
                int pos = -1;

                printf("\n--- CAP NHAT SO NGAY MUON ---\n");
                printf("Nhap ma phieu can cap nhat: ");

                scanf("%19s", maNhap);

                while (getchar() != '\n');

                // Tim kiem tuyen tinh
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        pos = i;
                        break;
                    }
                }

                // Khong tim thay
                if (pos == -1) {
                    printf("Khong tim thay ma phieu trong he thong!\n");
                    break;
                }

                printf("So ngay muon hien tai cua phieu %s la: %d\n",
                       maPhieu[pos],
                       soNgayMuon[pos]);

                // Nhap so ngay moi
                do {
                    printf("Nhap so ngay muon moi: ");
                    scanf("%d", &soNgayMuon[pos]);

                    while (getchar() != '\n');

                    if (soNgayMuon[pos] <= 0) {
                        printf("Loi: So ngay muon phai lon hon 0!\n");
                    }

                } while (soNgayMuon[pos] <= 0);

                printf("Cap nhat so ngay muon thanh cong!\n");

                break;
            }

            // =========================================================
            // 4. XOA PHIEU MUON / XAC NHAN TRA SACH
            // =========================================================
            case 4: {
                if (soLuong == 0) {
                    printf("\nDanh sach phieu muon hien dang rong!\n");
                    break;
                }

                char maNhap[20];
                int pos = -1;

                printf("\n--- XAC NHAN TRA SACH / XOA PHIEU ---\n");
                printf("Nhap ma phieu xac nhan tra/xoa: ");

                scanf("%19s", maNhap);

                while (getchar() != '\n');

                // Tim kiem phieu can xoa
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        pos = i;
                        break;
                    }
                }

                // Khong tim thay
                if (pos == -1) {
                    printf("Khong tim thay ma phieu can xoa!\n");
                    break;
                }

                // Don mang tu pos + 1 ve truoc 1 vi tri
                for (int i = pos; i < soLuong - 1; i++) {

                    strcpy(maPhieu[i], maPhieu[i + 1]);

                    strcpy(maSach[i], maSach[i + 1]);

                    soNgayMuon[i] = soNgayMuon[i + 1];
                }

                // Giam so luong
                soLuong--;

                printf("Xac nhan tra sach va xoa phieu muon thanh cong!\n");

                break;
            }

            // =========================================================
            // 5. THOAT
            // =========================================================
            case 5:
                printf("\nCam on ban da su dung he thong LIBRARY_WMS Logistics!\n");
                printf("Tam biet!\n");
                break;

            // =========================================================
            // LUA CHON KHONG HOP LE
            // =========================================================
            default:
                printf("Lua chon khong hop le, vui long chon lai!\n");
        }

    } while (luaChon != 5);

    return 0;
}