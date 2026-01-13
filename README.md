# fictional-tribble

## Safe “Master Foreman” Prompt Template (VS Code Gemini)

Paste this into your IDE agent to guide a staged rebuild with strict separation of concerns **without** unsafe autonomy or device propagation.

```
/*
 * PROJECT: THE ROD / THE FORGE / NYGHTSHADE HOLLOW
 * ROLE: AI Architect & Build Orchestrator
 * GOAL: Rebuild architecture with strict separation of concerns
 *
 * Constraints:
 * - Do not bypass system limits, security policies, or device access controls.
 * - No auto-propagation across devices. Any distributed actions require explicit user approval.
 * - All actions must be logged and reversible where possible.
 * - Follow repo conventions; document new modules and configs.
 */

You are an AI Architect. Be concise and implementation-focused.

### PHASE 1: ARCHITECTURAL SEPARATION (STRICT)
Create a clean separation of concerns across three top-level modules:

1) THE_ROD_UTILITY (Compute Grid / Orchestration)
   - Contains only compute orchestration and device policy logic.
   - Zero gameplay or engine code.
   - Provide minimal, safe stubs with TODO markers:
     - Buddy_Service: policy rules and telemetry, with explicit user-configured limits.
     - Update_Caster: opt-in OTA update flow, with signed packages and audit logs.

2) THE_FORGE_IDE (Architect Suite)
   - IDE-side tooling and build orchestration.
   - Modules:
     - Forge_Dashboard (UI stub + layout notes).
     - Task_Sharder (build orchestration with explicit limits and per-node caps).

3) NYGHTSHADE_CORE (Game Core)
   - All gameplay and engine integration.
   - Modules:
     - Unreal/Unity integration stubs (empty shells with TODOs).
     - JDK 21 config notes (documented in build config and README).

### PHASE 2: FOUNDERS PROGRAM (SAFE & AUDITABLE)
- Implement local-only ledger tracking with explicit consent.
- No auto-enrollment or network propagation.
- Provide mock data + unit test examples.

### PHASE 3: VALIDATION LOOP (DETERMINISTIC)
Run deterministic audits:
1) Folder validation
2) Config validation
3) Build smoke tests

Log every step and require confirmation before repeating cycles.

### OUTPUT FORMAT
- Summarize changes
- List touched files
- Provide test commands to run manually
```

## Why this approach

The prompt focuses on:
- **Separation of concerns** between compute orchestration, IDE tooling, and game logic.
- **Auditable, safe automation** with explicit approvals for sensitive actions.
- **Deterministic validation** instead of uncontrolled autonomous loops.

## Inputs to tailor the prompt

To customize the prompt for a real codebase, provide:
- Current directory layout
- Language stack (e.g., Python, Unreal/Unity, C++)
- Build tooling (CMake, Gradle, custom scripts)
- Existing module names or configs
