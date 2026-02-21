#!/bin/bash

# ==============================================================================
# epi-style - Epitech Coding Style Checker Wrapper
# ==============================================================================

# Configuration
DOCKER_IMAGE="ghcr.io/epitech/coding-style-checker:latest"
TARGET_DIR=$(pwd)
UPDATE_RULES=false
USE_DEFAULT_IGNORE=true
USE_GITIGNORE=true
DO_FIX=false
IGNORE_PATTERNS=()

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
BOLD='\033[1m'
NC='\033[0m' # No Color

# ------------------------------------------------------------------------------
# Helper Functions
# ------------------------------------------------------------------------------

function show_help() {
    echo -e "${BOLD}Usage:${NC} $(basename "$0") [OPTIONS] [DELIVERY_DIR]"
    echo ""
    echo -e "An optimized runner for the Epitech Coding Style Checker."
    echo ""
    echo -e "${BOLD}Options:${NC}"
    echo -e "  --fix               Automatically fix formatting errors using clang-format"
    echo -e "  --ignore LIST       Comma-separated list of patterns to ignore (e.g. \"*.a,tests/*\")"
    echo -e "  --no-default-ignore Do not load the 'default_ignore' file"
    echo -e "  --no-gitignore      Do not load the '.gitignore' file"
    echo -e "  --update-rules      Update the docker image before running (docker pull)"
    echo -e "  --help              Show this help message"
    echo ""
    echo -e "${BOLD}Arguments:${NC}"
    echo -e "  DELIVERY_DIR        Directory to check (default: current directory)"
    echo ""
}

function get_rule_description() {
    local rule=$1
    case $rule in
        "C-O1") echo "Compiled, temporary, or unnecessary files in repository" ;;
        "C-O2") echo "Invalid file extension (must be .c or .h)" ;;
        "C-O3") echo "Too many functions in file (>10 total or >5 non-static)" ;;
        "C-O4") echo "File naming convention violated (snake_case required)" ;;
        "C-G1") echo "Missing or invalid Epitech Header" ;;
        "C-G2") echo "Function separation (must be exactly 1 empty line)" ;;
        "C-G3") echo "Preprocessor directive indentation" ;;
        "C-G4") echo "Global variable usage (only constants allowed)" ;;
        "C-G5") echo "Invalid include (only .h files allowed)" ;;
        "C-G6") echo "Invalid line ending (must be UNIX style \\n)" ;;
        "C-G7") echo "Trailing spaces at end of line" ;;
        "C-G8") echo "Leading/Trailing empty lines (max 1 at end)" ;;
        "C-G9") echo "Non-trivial constant (use macros or const)" ;;
        "C-G10") echo "Inline assembly usage" ;;
        "C-F1") echo "Incoherent function (Single Responsibility Principle violated)" ;;
        "C-F2") echo "Invalid function name (verb + snake_case)" ;;
        "C-F3") echo "Line too long (> 80 columns)" ;;
        "C-F4") echo "Function too long (> 20 lines)" ;;
        "C-F5") echo "Too many parameters (> 4)" ;;
        "C-F6") echo "Function with no parameters missing 'void'" ;;
        "C-F7") echo "Structure passed by value (use pointers)" ;;
        "C-F8") echo "Comments inside function body" ;;
        "C-L1") echo "Multiple statements on the same line" ;;
        "C-L2") echo "Incorrect indentation (use 4 spaces, no tabs)" ;;
        "C-L3") echo "Missing/Extra space (operators/keywords)" ;;
        "C-L4") echo "Misplaced curly brackets" ;;
        "C-L5") echo "Variable declaration placement (start of scope)" ;;
        "C-L6") echo "Missing blank line after declarations" ;;
        "C-V1") echo "Identifier naming convention (snake_case / MACRO_UPPER)" ;;
        "C-V2") echo "Structure incoherent or too complex" ;;
        "C-V3") echo "Pointer asterisk placement (int *ptr)" ;;
        "C-C1") echo "Conditional branching depth > 3" ;;
        "C-C2") echo "Complex or nested ternary operator" ;;
        "C-C3") echo "Goto keyword usage" ;;
        "C-H1") echo "Code in header file (only protos/macros/structs)" ;;
        "C-H2") echo "Missing or invalid Include Guard" ;;
        "C-H3") echo "Multi-line or complex macro" ;;
        "C-A1") echo "Unmodified variable not marked as const" ;;
        "C-A2") echo "Weak typing / imprecise types" ;;
        "C-A3") echo "File must end with a line break (\\n)" ;;
        "C-A4") echo "Global function/var not static but not used elsewhere" ;;
        *) echo "Generic Coding Style Error" ;;
    esac
}

# Check if a file matches any ignore pattern or is inside an ignored directory
function is_ignored() {
    local file="$1"
    for pattern in "${IGNORE_PATTERNS[@]}"; do
        local clean_pattern="${pattern%/}"
        
        if [[ "$file" == $pattern ]]; then
            return 0
        fi
        
        if [[ "$file" == "$clean_pattern"/* ]]; then
            return 0
        fi

        if [[ "$file" == "$clean_pattern" ]]; then
            return 0
        fi
    done
    return 1
}

function generate_clang_format() {
    cat <<EOF > .epi-style-clang-format
BasedOnStyle: Google
IndentWidth: 4
TabWidth: 4
UseTab: Never
ColumnLimit: 80
AccessModifierOffset: -4
AlignAfterOpenBracket: Align
AlignConsecutiveMacros: true
AlignConsecutiveAssignments: false
AlignConsecutiveDeclarations: false
AlignEscapedNewlines: Right
AlignOperands: true
AlignTrailingComments: true
AllowShortBlocksOnASingleLine: false
AllowShortCaseLabelsOnASingleLine: false
AllowShortFunctionsOnASingleLine: None
AllowShortIfStatementsOnASingleLine: false
AllowShortLoopsOnASingleLine: false
BreakBeforeBraces: Custom
BraceWrapping:
  AfterCaseLabel: false
  AfterClass: true
  AfterControlStatement: false
  AfterEnum: true
  AfterFunction: true
  AfterNamespace: true
  AfterStruct: true
  AfterUnion: true
  AfterExternBlock: false
  BeforeCatch: false
  BeforeElse: false
  SplitEmptyFunction: false
  SplitEmptyRecord: false
BreakBeforeBinaryOperators: None
BreakBeforeTernaryOperators: true
BreakStringLiterals: true
ContinuationIndentWidth: 4
PointerAlignment: Right
SortIncludes: false
SpaceAfterCStyleCast: false
SpaceAfterLogicalNot: false
SpaceAfterTemplateKeyword: true
SpaceBeforeAssignmentOperators: true
SpaceBeforeCpp11BracedList: false
SpaceBeforeCtorInitializerColon: true
SpaceBeforeInheritanceColon: true
SpaceBeforeParens: ControlStatements
SpaceBeforeRangeBasedForLoopColon: true
SpaceInEmptyParentheses: false
SpacesInAngles: false
SpacesInCStyleCastParentheses: false
SpacesInContainerLiterals: true
SpacesInParentheses: false
SpacesInSquareBrackets: false
EOF
}

function run_fixer() {
    echo -e "${BLUE}Running Clang-Format Fixer...${NC}"

    if ! command -v clang-format &> /dev/null; then
        echo -e "${RED}Error: clang-format is not installed.${NC}"
        echo -e "Please install it using: ${BOLD}sudo pacman -S clang${NC}"
        return
    fi

    # Generate config
    generate_clang_format

    # Find C and H files
    while IFS= read -r -d '' file; do
        # Strip leading ./
        clean_file=$(echo "$file" | sed 's/^\.\///')

        if is_ignored "$clean_file"; then
            continue
        fi

        echo -e "Formatting: $clean_file"
        clang-format -i -style=file:.epi-style-clang-format "$file"

    done < <(find . -type f \( -name "*.c" -o -name "*.h" \) -print0)

    # Cleanup
    rm -f .epi-style-clang-format
    echo -e "${GREEN}Fixing complete!${NC}"
    echo ""
}

# ------------------------------------------------------------------------------
# Argument Parsing
# ------------------------------------------------------------------------------

while [[ "$#" -gt 0 ]]; do
    case $1 in
        --update-rules) UPDATE_RULES=true ;;
        --fix) DO_FIX=true ;;
        --no-default-ignore) USE_DEFAULT_IGNORE=false ;;
        --no-gitignore) USE_GITIGNORE=false ;;
        --ignore)
            shift
            IFS=',' read -ra ADDR <<< "$1"
            for i in "${ADDR[@]}"; do
                IGNORE_PATTERNS+=("$i")
            done
            ;;
        --help) show_help; exit 0 ;;
        -*) echo "Unknown option: $1"; show_help; exit 1 ;;
        *) TARGET_DIR="$1" ;;
    esac
    shift
done

# ------------------------------------------------------------------------------
# Load Ignore Files
# ------------------------------------------------------------------------------

SCRIPT_PATH=$(realpath "$0")
SCRIPT_DIR=$(dirname "$SCRIPT_PATH")

# 1. Load default_ignore
DEFAULT_IGNORE_FILE="$SCRIPT_DIR/default_ignore"
if [ "$USE_DEFAULT_IGNORE" = true ] && [ -f "$DEFAULT_IGNORE_FILE" ]; then
    while IFS= read -r line; do
        [[ "$line" =~ ^#.*$ ]] && continue
        [[ -z "$line" ]] && continue
        IGNORE_PATTERNS+=("$line")
    done < "$DEFAULT_IGNORE_FILE"
fi

# 2. Load .gitignore (Context dependent)
if [ "$USE_GITIGNORE" = true ] && [ -f "$TARGET_DIR/.gitignore" ]; then
    while IFS= read -r line; do
        [[ "$line" =~ ^#.*$ ]] && continue
        [[ -z "$line" ]] && continue
        IGNORE_PATTERNS+=("$line")
    done < "$TARGET_DIR/.gitignore"
fi

# ------------------------------------------------------------------------------
# Main Execution
# ------------------------------------------------------------------------------

if [ ! -d "$TARGET_DIR" ]; then
    echo -e "${RED}Error: Directory '$TARGET_DIR' does not exist.${NC}"
    exit 1
fi

cd "$TARGET_DIR" || exit 1
TARGET_DIR=$(pwd)

# Print ignore patterns if any
if [ ${#IGNORE_PATTERNS[@]} -gt 0 ]; then
    echo -e "${YELLOW}Ignore active (default + .gitignore + args).${NC}"
fi

if [ "$DO_FIX" = true ]; then
    run_fixer
fi

if [ "$UPDATE_RULES" = true ]; then
    echo -e "${BLUE}Updating Coding Style Docker image...${NC}"
    docker pull "$DOCKER_IMAGE"
fi

REPORT_DIR=$(mktemp -d)
REPORT_FILE="$REPORT_DIR/coding-style-reports.log"

cleanup() {
    rm -rf "$REPORT_DIR"
    rm -f .epi-style-clang-format # Just in case
}
trap cleanup EXIT

echo -e "${BLUE}Running analysis on: ${BOLD}$TARGET_DIR${NC}"

docker run --rm \
    --security-opt "label:disable" \
    -i \
    -v "$TARGET_DIR":"/mnt/delivery" \
    -v "$REPORT_DIR":"/mnt/reports" \
    "$DOCKER_IMAGE" \
    "/mnt/delivery" "/mnt/reports"

if [ ! -f "$REPORT_FILE" ]; then
    echo -e "${RED}Error: Report file generation failed.${NC}"
    exit 1
fi

RAW_ERROR_COUNT=$(wc -l < "$REPORT_FILE")
DISPLAYED_ERRORS=0

echo ""

while IFS=':' read -r FILE LINE SEVERITY RULE; do
    CLEAN_FILE=$(echo "$FILE" | sed 's/^\.\///')

    if is_ignored "$CLEAN_FILE"; then
        continue
    fi

    SEVERITY=$(echo "$SEVERITY" | xargs)
    RULE=$(echo "$RULE" | xargs)

    COLOR=$NC
    ICON=" "
    if [ "$SEVERITY" == "MAJOR" ]; then
        COLOR=$RED
        ICON="🛑 "
    elif [ "$SEVERITY" == "MINOR" ]; then
        COLOR=$YELLOW
        ICON="⚠️ "
    elif [ "$SEVERITY" == "INFO" ]; then
        COLOR=$BLUE
        ICON="ℹ️ "
    fi

    DESC=$(get_rule_description "$RULE")

    echo -e "${BOLD}$CLEAN_FILE:$LINE${NC} \t $ICON ${COLOR}$SEVERITY${NC} \t ${BOLD}$RULE${NC}: $DESC"
    ((DISPLAYED_ERRORS++))

done < "$REPORT_FILE"

echo ""
if [ "$DISPLAYED_ERRORS" -eq 0 ]; then
    if [ "$RAW_ERROR_COUNT" -gt 0 ]; then
         echo -e "${GREEN}${BOLD}No errors found (some were hidden by ignore filters).${NC}"
    else
         echo -e "${GREEN}${BOLD}No coding style errors found. Great job! 🍌${NC}"
    fi
else
    echo -e "${RED}${BOLD}Found $DISPLAYED_ERRORS error(s)${NC}"
fi

exit 0
