import customtkinter as ctk


class FounderAlert(ctk.CTkToplevel):
    def __init__(self):
        super().__init__()
        self.title("ROD SONAR ALERT")
        self.geometry("600x400")
        self.attributes("-topmost", True)
        self.configure(fg_color="#0b0d17")

        label = ctk.CTkLabel(
            self,
            text="FOUNDING FLEET VERIFIED",
            font=("Impact", 35),
            text_color="#00f2ff",
        )
        label.pack(pady=30)

        msg = (
            "Welcome to the Republic, Angler.\n\n"
            "You are one of the First 100.\n"
            "LIFETIME ACCESS GRANTED: Nyghtshade Hollow\n"
            "AC GRANT: 10,000 Credits Initialized.\n\n"
            "The Forge does not forget its founders."
        )

        ctk.CTkLabel(self, text=msg, font=("Inter", 16), text_color="#f5f7ff").pack(
            pady=10
        )
        ctk.CTkButton(
            self,
            text="CLAIM REWARDS",
            fg_color="#00ff88",
            text_color="#000",
            command=self.destroy,
        ).pack(pady=30)


if __name__ == "__main__":
    app = ctk.CTk()
    alert = FounderAlert()
    app.mainloop()
