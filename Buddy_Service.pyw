import json
import os
import subprocess
import threading
import time

from pynput import keyboard, mouse


class RodSentry:
    def __init__(self):
        self.ledger_path = "C:\\ProgramData\\TheForge\\angler_ledger.json"
        self.is_server = (
            "Server" in subprocess.check_output("wmic os get caption", shell=True).decode()
        )
        self.last_activity = time.time()
        self.total_trawl_time = self.load_ledger()
        self.is_founder = False

    def load_ledger(self):
        if os.path.exists(self.ledger_path):
            with open(self.ledger_path, "r", encoding="utf-8") as ledger_file:
                return json.load(ledger_file).get("time", 0)
        return 0

    def save_ledger(self):
        with open(self.ledger_path, "w", encoding="utf-8") as ledger_file:
            json.dump(
                {"time": self.total_trawl_time, "founder": self.is_founder}, ledger_file
            )

    def run_sentry(self):
        if self.is_server:
            subprocess.run(
                "powercfg /setactive e9a42b02-d5df-448d-aa00-03f14749eb61",
                shell=True,
                check=False,
            )
            self.compute_loop(pull=1.0)
        else:
            threading.Thread(target=self.input_monitor, daemon=True).start()
            self.compute_loop()

    def input_monitor(self):
        def reset(*_args):
            self.last_activity = time.time()

        with mouse.Listener(on_move=reset) as mouse_listener, keyboard.Listener(
            on_press=reset
        ) as keyboard_listener:
            mouse_listener.join()
            keyboard_listener.join()

    def compute_loop(self, pull=0.25):
        while True:
            idle_dur = time.time() - self.last_activity
            if idle_dur > 600:
                self.total_trawl_time += 10
                if self.total_trawl_time >= 86400 and not self.is_founder:
                    self.is_founder = True
                    print("[ROD] FOUNDING FLEET MILESTONE REACHED.")
            self.save_ledger()
            time.sleep(10)


if __name__ == "__main__":
    sentry = RodSentry()
    sentry.run_sentry()
