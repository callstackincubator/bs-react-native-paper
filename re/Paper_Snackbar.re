[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "Snackbar";

[@bs.module "react-native-paper"] [@bs.scope "Snackbar"]
external durationShort: int = "DURATION_SHORT";
[@bs.module "react-native-paper"] [@bs.scope "Snackbar"]
external durationMedium: int = "DURATION_MEDIUM";
[@bs.module "react-native-paper"] [@bs.scope "Snackbar"]
external durationLong: int = "DURATION_LONG";

type duration =
  | DurationShort
  | DurationMedium
  | DurationLong
  | Duration(int);

let getDuration = d =>
  switch (d) {
  | DurationShort => durationShort
  | DurationMedium => durationMedium
  | DurationLong => durationLong
  | Duration(duration) => duration
  };

[@bs.deriving abstract]
type snackbarAction = {
  label: string,
  onPress: unit => unit,
};

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
  [@bs.optional]
  duration: int,
  onDismiss: unit => unit,
  [@bs.optional]
  style: Rebolt.Style.t,
  [@bs.optional]
  action: snackbarAction,
  visible: bool,
};

let make =
    (
      ~theme=?,
      ~duration=?,
      ~onDismiss,
      ~style=?,
      ~action=?,
      ~visible,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      props(
        ~theme?,
        ~duration=
          switch (duration) {
          | Some(duration) => getDuration(duration)
          | None => getDuration(DurationMedium)
          },
        ~onDismiss,
        ~style?,
        ~action?,
        ~visible,
        (),
      ),
    children,
  );
