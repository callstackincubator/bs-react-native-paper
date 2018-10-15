open BsReactNative;
open Paper;

module Styles = {
  open Style;

  let view = style([flexDirection(Row), alignItems(Center)]);

  let scrollArea =
    style([maxHeight(Pt(170.)), paddingHorizontal(Pt(0.))]);

  let row =
    style([
      flexDirection(Row),
      alignItems(Center),
      paddingHorizontal(Pt(16.)),
      paddingVertical(Pt(8.)),
    ]);
};

type checked =
  | FirstChecked
  | SecondChecked
  | ThirdChecked
  | FourthChecked;

type state = {radioChecked: checked};

type action =
  | ChangeCheckedStatus(checked);

let component = ReasonReact.reducerComponent("DialogWithRadioButtons");

let make = (~close, ~visible, _children) => {
  ...component,
  initialState: () => {radioChecked: FirstChecked},
  reducer: (action, _state) =>
    switch (action) {
    | ChangeCheckedStatus(status) =>
      ReasonReact.Update({radioChecked: status})
    },
  render: self =>
    <Portal>
      <Dialog onDismiss=close visible>
        <Dialog.Title>
          {ReasonReact.string("Choose an option")}
        </Dialog.Title>
        <Dialog.ScrollArea style=Styles.scrollArea>
          <ScrollView>
            <View>
              <TouchableRipple
                onPress={
                  _event => self.send(ChangeCheckedStatus(FirstChecked))
                }>
                <View style=Styles.row>
                  <View pointerEvents=`none>
                    <RadioButton
                      value="first"
                      status={
                        switch (self.state.radioChecked) {
                        | FirstChecked => `checked
                        | _ => `unchecked
                        }
                      }
                    />
                  </View>
                  <Subheading> {ReasonReact.string("Option 1")} </Subheading>
                </View>
              </TouchableRipple>
              <TouchableRipple
                onPress={
                  _event => self.send(ChangeCheckedStatus(SecondChecked))
                }>
                <View style=Styles.row>
                  <View pointerEvents=`none>
                    <RadioButton
                      value="second"
                      status={
                        switch (self.state.radioChecked) {
                        | SecondChecked => `checked
                        | _ => `unchecked
                        }
                      }
                    />
                  </View>
                  <Subheading> {ReasonReact.string("Option 2")} </Subheading>
                </View>
              </TouchableRipple>
              <TouchableRipple
                onPress={
                  _event => self.send(ChangeCheckedStatus(ThirdChecked))
                }>
                <View style=Styles.row>
                  <View pointerEvents=`none>
                    <RadioButton
                      value="third"
                      status={
                        switch (self.state.radioChecked) {
                        | ThirdChecked => `checked
                        | _ => `unchecked
                        }
                      }
                    />
                  </View>
                  <Subheading> {ReasonReact.string("Option 3")} </Subheading>
                </View>
              </TouchableRipple>
              <TouchableRipple
                onPress={
                  _event => self.send(ChangeCheckedStatus(FourthChecked))
                }>
                <View style=Styles.row>
                  <View pointerEvents=`none>
                    <RadioButton
                      value="fourth"
                      status={
                        switch (self.state.radioChecked) {
                        | FourthChecked => `checked
                        | _ => `unchecked
                        }
                      }
                    />
                  </View>
                  <Subheading> {ReasonReact.string("Option 4")} </Subheading>
                </View>
              </TouchableRipple>
            </View>
          </ScrollView>
        </Dialog.ScrollArea>
        <Dialog.Actions>
          <Button onPress={_event => close()}>
            {ReasonReact.string("Cancel")}
          </Button>
          <Button onPress={_event => close()}>
            {ReasonReact.string("OK")}
          </Button>
        </Dialog.Actions>
      </Dialog>
    </Portal>,
};
